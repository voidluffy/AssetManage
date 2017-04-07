<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWidget</class>
 <widget class="QWidget" name="MainWidget">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>998</width>
    <height>711</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Form</string>
  </property>
  <layout class="QVBoxLayout" name="verticalLayout">
   <property name="spacing">
    <number>0</number>
   </property>
   <property name="leftMargin">
    <number>0</number>
   </property>
   <property name="topMargin">
    <number>0</number>
   </property>
   <property name="rightMargin">
    <number>0</number>
   </property>
   <property name="bottomMargin">
    <number>0</number>
   </property>
   <item>
    <widget class="QWidget" name="widget_container" native="true">
     <property name="styleSheet">
      <string notr="true">QWidget#widget_container
{
    background-color: rgb(22, 22, 22);
    border:1px solid rgba(0, 0, 0, 30);
    border-radius:2px;  /*边框拐角*/
}
</string>
     </property>
     <layout class="QVBoxLayout" name="verticalLayout_3">
      <property name="spacing">
       <number>0</number>
      </property>
      <property name="leftMargin">
       <number>0</number>
      </property>
      <property name="topMargin">
       <number>0</number>
      </property>
      <property name="rightMargin">
       <number>0</number>
      </property>
      <property name="bottomMargin">
       <number>0</number>
      </property>
      <item>
       <layout class="QHBoxLayout" name="horizontalLayout_6">
        <property name="spacing">
         <number>0</number>
        </property>
        <property name="rightMargin">
         <number>0</number>
        </property>
        <property name="bottomMargin">
         <number>0</number>
        </property>
        <item>
         <layout class="QVBoxLayout" name="verticalLayout_4">
          <property name="spacing">
           <number>0</number>
          </property>
          <property name="topMargin">
           <number>0</number>
          </property>
          <property name="rightMargin">
           <number>0</number>
          </property>
          <item>
           <widget class="QWidget" name="widget_video" native="true">
            <property name="minimumSize">
             <size>
              <width>100</width>
              <height>0</height>
             </size>
            </property>
            <property name="maximumSize">
             <size>
              <width>200</width>
              <height>16777215</height>
             </size>
            </property>
            <property name="styleSheet">
             <string notr="true"/>
            </property>
            <layout class="QVBoxLayout" name="verticalLayout_2">
             <property name="spacing">
              <number>0</number>
             </property>
             <property name="leftMargin">
              <number>0</number>
             </property>
             <property name="topMargin">
              <number>0</number>
             </property>
             <property name="rightMargin">
              <number>0</number>
             </property>
             <property name="bottomMargin">
              <number>0</number>
             </property>
             <item>
              <widget class="QTreeWidget" name="treeWidget">
               <column>
                <property name="text">
                 <string notr="true">1</string>
                </property>
               </column>
              </widget>
             </item>
            </layout>
           </widget>
          </item>
         </layout>
        </item>
        <item>
         <widget class="QWidget" name="widget_right" native="true">
          <property name="sizePolicy">
           <sizepolicy hsizetype="Expanding" vsizetype="Expanding">
            <horstretch>0</horstretch>
            <verstretch>0</verstretch>
           </sizepolicy>
          </property>
          <property name="styleSheet">
           <string notr="true">background-color: rgb(0, 0, 0);</string>
          </property>
          <layout class="QVBoxLayout" name="verticalLayout_6">
           <item>
            <widget class="QStackedWidget" name="stackedWidget">
             <widget class="QWidget" name="page">
              <zorder>groupBox</zorder>
              <zorder>groupBox</zorder>
              <zorder>groupBox</zorder>
             </widget>
             <widget class="QWidget" name="page_2"/>
            </widget>
           </item>
          </layout>
         </widget>
        </item>
       </layout>
      </item>
     </layout>
    </widget>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections/>
</ui>
