%modules = ( # path to module name map
    "Qt5AccountsService" => "$basedir/src/accountsservice",
);
%moduleheaders = ( # restrict the module headers to those found in relative path
    "qtaccountsserviceglobal.h"
);
%classnames = (
    "accountsmanager.h" => "QtAccountsService::AccountsManager",
    "useraccount.h" => "QtAccountsService::UserAccount",
    "usersmodel.h" => "QtAccountsService::UsersModel",
);
