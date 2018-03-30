#include <odbc++/drivermanager.h>
#include <odbc++/connection.h>
#include <odbc++/resultset.h>
#include <odbc++/resultsetmetadata.h>
#include <odbc++/preparedstatement.h>
#include <iostream>

using namespace std;
using namespace odbc;

int main(int argc, char **argv) 
{
    //Get the Driver manager

    DriverManager *dm;

    //Open the connection, specifiying the DSN.
    Connection *c = dm->getConnection("DSN=PostgreSQL test");
    //Create the Query
    PreparedStatement *s = c->prepareStatement(
            ODBCXX_STRING_CONST("SELECT _id,email_address FROM nav_user"));


    ResultSet *r;
    //Execute the Query
    s->execute();


    //Get initial ResultSet
    r = s->getResultSet();


    while(r->next())
    {


        //Extract column information
        cout << "Column (Id): " << r->getString("_id") << endl;
        cout << "Column (Name): " << r->getString("email_address") << endl;
    }

    //Clean everything
    delete r;
    delete s;
    delete c;

    return 0;
}
