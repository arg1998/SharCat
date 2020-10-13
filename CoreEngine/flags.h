#ifndef FLAGS_H
#define FLAGS_H
#include <QString>


enum ReturnType
{
    FullText , SelectedLine , Nothing
};
enum Property
{
    //person
   FNAME ,LNAME , ID ,EMAIL , GENDER , USERNAME , DATE , PHONE , MODIFICATIONDATE,
    //student
   FIELDNAME , CURRENTTERM , TOTALTERMS , TOTALUNITS , PASSEDUNITS , ENTRYYEAR ,
    //teacher
   DEGREE , FIELD , SCIENTIFICBOARD , HOURSWEEK ,
    //staff
    DEPARTMENT , TYPE , WORKSHIFT ,
	//setting
    THEME , SHOW_CONSOLE , PASSWORD
};
enum Fields
{
    ComputerENG , ChemistryENG , IndustrialENG , PetroleumENG
};



static QString PropertyString(Property p)
{
    switch (p) {


    //person class
    case Property::LNAME :
        return "LNAME";
        break;

    case Property::MODIFICATIONDATE :
        return "MODIFICATIONDATE";
        break;

    case Property::FNAME :
        return "FNAME";
        break;

    case Property::ID :
        return "ID";
        break;

    case Property::EMAIL :
        return "EMAIL";
        break;

    case Property::GENDER :
        return "GENDER";
        break;


    case Property::USERNAME :
        return "USERNAME";
        break;

    case Property::DATE :
        return "DATE";
        break;

    case Property::PHONE :
        return "PHONE";
        break;


        //student class
    case Property::FIELDNAME :
        return "FIELDNAME";
        break;

    case Property::ENTRYYEAR :
        return "ENTRYYEAR";
        break;

    case Property::CURRENTTERM :
        return "CURRENTTERM";
        break;

    case Property::TOTALTERMS :
        return "TOTALTERMS";
        break;

    case Property::TOTALUNITS :
        return "TOTALUNITS";
        break;

    case Property::PASSEDUNITS :
        return "PASSEDUNITS";
        break;

        //teacher
    case Property::DEGREE :
        return "DEGREE";
        break;

    case Property::FIELD :
        return "FIELD";
        break;

    case Property::SCIENTIFICBOARD :
        return "SCIENTIFICBOARD";
        break;

    case Property::HOURSWEEK :
        return "HOURSWEEK";
        break;

        //staff
    case Property::DEPARTMENT :
        return "DEPARTMENT";
        break;

    case Property::TYPE :
        return "TYPE";
        break;

    case Property::WORKSHIFT :
        return "WORKSHIFT";
        break;
		
		
		//setting
    case Property::THEME:
        return "THEME";
        break;
    case Property::SHOW_CONSOLE:
        return "SHOW_CONSOLE";
       break;
    case Property::PASSWORD:
        return "PASSWORD";
        break;



    default:
        break;
    }
    return "";
}
static QString FiledsToString(Fields field)
{
    switch (field)
    {

    case Fields::ComputerENG:
        return "Computer ENG";

    case Fields::ChemistryENG:
        return "Chemistry ENG";

    case Fields::IndustrialENG:
        return "Industrial ENG";

    case Fields::PetroleumENG:
        return "Petroleum ENG";

        break;
    default:
        break;
    }
    return "";
}


#endif // FLAGS_H
