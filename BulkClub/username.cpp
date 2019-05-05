#include "username.h"
#include <QString>
#include <QDebug>

/****************************************************************************
 * DEFAULT CONSTRUCTOR
 * --------------------------------------------------------------------------
 * Sets name of the username object to "Blue Sandshrew Member"
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      name variable declared;
 *
 * POST-CONDITIONS
 *      ==> updates name variable to "Blue Sandshrew Member"
 ***************************************************************************/
userName::userName()
{
name = "Blue Sandshrew Member";
}

/****************************************************************************
 * CONSTRUCTOR
 * --------------------------------------------------------------------------
 * Sets name of the username object to a passed string
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      name variable declared;
 *
 * POST-CONDITIONS
 *      ==> updates name variable to the passed string
 ***************************************************************************/
userName::userName(QString newName)
{
name = newName;
}

/****************************************************************************
 * COPY CONSTRUCTOR
 * --------------------------------------------------------------------------
 * Initializes a username object to the values of the passed username object
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      name variable declared, username object passed;
 *
 * POST-CONDITIONS
 *      ==> updates name value to match name value of passed username object
 ***************************************************************************/
userName::userName(const userName& other)
{
    qDebug() << "Copy Constructor Called"; //Testing to make sure copy constructor is called
    name = other.name;
}

/****************************************************************************
 * getName()
 * --------------------------------------------------------------------------
 *  Returns the name of a userName object
 * --------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      name variable declared and initialized;
 *
 * POST-CONDITIONS
 *      ==> returns the name of the userName object
 ***************************************************************************/
QString userName::getName()
{
    return name;
}

