/* Copyright (c) 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef APP_H
#define APP_H

#include <QtCore/QObject>
#include <bb/cascades/Application>
#include <bb/cascades/QListDataModel>
//#include <bb/cascades/XmlDataModel>

namespace bb
{
namespace cascades
{
class AbstractPane;
class ListView;
class NavigationPane;
class Button;
//class DataModel;
}
}

/**
 * Scrollbar application
 *
 */
class App : public QObject
{
    Q_OBJECT

public:
    App();

    /*
     * Exposed function that is called by the QML to add elements to a ListView
     *
     * @param The position in the ListView to insert the new items
     */
    Q_INVOKABLE
    void addItems(int index);

private slots:

    /**
     * Slot function for selection in the cpp list.
     *
     * @param indexPath Index path to the item.
     * @param active True if the new state is selected, otherwise false.
     */
    void onSelectionChanged(const QVariantList indexPath, bool selected);

    /**
     * Slot function that receives signals when the top Control has changed in the
     * NavigationPane.
     */
    void onTopChanged(bb::cascades::AbstractPane* pane);

private:

    /**
     * Function that finds the container in the QML that the list view
     * will be added to. Creates the inner containers, and inserts the list
     * view into it.
     */
    void setupCppListView();

    /**
     * Creates the initial data for the qml list
     */
    void setupQmlListModelData();

    /**
     * Function that initializes the list
     */
    bb::cascades::ListView* createCppListView();

    /*
     * Adds @c numElementsToInsert starting at index @c insertIndex into the data model @c dataModel
     * @param dataModel Reference to the data model to add elements to
     * @param insertIndex Index to start inserting items
     * @param numElementsToInsert The number of elements that will be added to dataModel
     */
    void addItems(bb::cascades::QVariantListDataModel& dataModel, int insertIndex, int numElementsToInsert);

    // Data Model for the lists
    bb::cascades::QVariantListDataModel m_cppListDataModel;
    bb::cascades::QVariantListDataModel m_qmlListDataModel;

    // A navigation pane is used to navigate the list
    bb::cascades::NavigationPane* m_navPane;

    // The lists
    bb::cascades::ListView* m_cppListView;
    bb::cascades::ListView* m_qmlListView;
};

#endif // ifndef APP_H
