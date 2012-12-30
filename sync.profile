%modules = ( # path to module name map
    "QtAccountsService" => "$basedir/src/accountsservice",
);
%moduleheaders = ( # restrict the module headers to those found in relative path
);
%mastercontent = (
    "accountsservice" => "#include <QtAccountsService/QtAccountsService>\n",
);
%modulepris = (
    "QtAccountsService" => "$basedir/modules/qt_accountsservice.pri",
);
%classnames = (
    "accountsmanager.h" => "AccountsManager",
    "useraccount.h" => "UserAccount"
);
# Module dependencies.
# Every module that is required to build this module should have one entry.
# Each of the module version specifiers can take one of the following values:
#   - A specific Git revision.
#   - any git symbolic ref resolvable from the module's repository (e.g. "refs/heads/master" to track master branch)
#
%dependencies = (
    "qtbase" => "refs/heads/stable",
);
