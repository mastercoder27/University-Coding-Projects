// test code that can be pasted into main.cpp
// also examples of unit testing that should be 
// replicated for testing of the Date class        
        
        
        /****************************************************************************
         ****************************************************************************
         **                                                                        **
         **                      class Time test code                              **
         **                                                                        **
         **                 This code is provided to students                      **
         **                 in COSC 052 Fall 2021 to use in                        **
         **                 part or in total for class projects.                   **
         **                 Students may use this code as their                    **
         **                 own, without any attribution.                          **
         **                                                                        **
         **                 This test code is an example of testing                **
         **                 that you should implement for your Date                **
         **                 class and other classes in this project.               **
         **                                                                        **
         **                 To use this code, copy and paste into                  **
         **                 your driver program.  It should be placed              **
         **                 inside of your large, outer try block.                 **
         **                                                                        **
         ****************************************************************************
         ****************************************************************************/
        

        ///*
        
        int testCount = 0, passCount = 0, failCount = 0;
        string tSpacer = "";
        tSpacer.assign(40,'-');
        tSpacer.append("\n");
        int w1 = 50, w2 = 30;
        int c1 = 20, c2 = 20;
        

        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, getter methods..." << endl;
        try
        {
            Time t1;
            if ( t1.getHour() == DEFAULT_HOUR && t1.getMinute() == DEFAULT_MINUTE )
            {
                cout << "\tPASS." << endl; passCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL." << endl; failCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL." << endl; failCount++;
        }
        cout << "End test.\n" << endl;

        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, getter methods..." << endl;
        try
        {
            int hValue = 13;
            Time t1(hValue);
            if ( t1.getHour() == hValue && t1.getMinute() == DEFAULT_MINUTE )
            {
                cout << "\tPASS." << endl; passCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL." << endl; failCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, getter methods..." << endl;
        try
        {
            int hValue = 13, mValue = 49;
            Time t1(hValue, mValue);
            if ( t1.getHour() == hValue && t1.getMinute() == mValue )
            {
                cout << "\tPASS." << endl; passCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL." << endl; failCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, setTime, getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1;
            t1.setTime(hValue, mValue);
            if ( t1.getHour() == hValue && t1.getMinute() == mValue )
            {
                cout << "\tPASS." << endl; passCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL." << endl; failCount++;
                cout << "\thour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructors, overloaded assignment operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1;
            Time t2(hValue, mValue);
            t1 = t2;
            if ( t1.getHour() == t2.getHour() && t2.getHour() == hValue &&
                 t1.getMinute() == t2.getMinute() && t2.getMinute() == mValue )
            {
                cout << "\tPASS t1 = t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 = t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 = t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded equality operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue, mValue);
            if ( t1 == t2 )
            {
                cout << "\tPASS t1 == t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 == t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 == t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded equality operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue+1, mValue);
            if ( t1 == t2 )
            {
                cout << "\tFAIL t1 == t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 == t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 == t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded equality operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue, mValue+1);
            if ( t1 == t2 )
            {
                cout << "\tFAIL t1 == t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 == t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 == t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded inequality operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue, mValue);
            if ( t1 != t2 )
            {
                cout << "\tFAIL t1 != t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 != t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 != t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded inequality operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue+1, mValue);
            if ( t1 != t2 )
            {
                cout << "\tPASS t1 != t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 != t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 != t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded inequality operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue, mValue+1);
            if ( t1 != t2 )
            {
                cout << "\tPASS t1 != t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 != t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 != t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded > operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue, mValue);
            if ( t1 > t2 )
            {
                cout << "\tFAIL t1 > t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 > t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 > t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded > operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue-1, mValue);
            Time t2(hValue, mValue);
            if ( t1 > t2 )
            {
                cout << "\tFAIL t1 > t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 > t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 > t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded > operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue-1);
            Time t2(hValue, mValue);
            if ( t1 > t2 )
            {
                cout << "\tFAIL t1 > t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 > t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 > t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded > operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue+1, mValue);
            Time t2(hValue, mValue);
            if ( t1 > t2 )
            {
                cout << "\tPASS t1 > t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 > t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 > t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded > operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue+1);
            Time t2(hValue, mValue);
            if ( t1 > t2 )
            {
                cout << "\tPASS t1 > t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 > t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 > t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded < operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue);
            Time t2(hValue, mValue);
            if ( t1 < t2 )
            {
                cout << "\tFAIL t1 < t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 < t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 < t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded < operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue+1, mValue);
            Time t2(hValue, mValue);
            if ( t1 < t2 )
            {
                cout << "\tFAIL t1 < t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 < t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 < t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded < operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue+1);
            Time t2(hValue, mValue);
            if ( t1 < t2 )
            {
                cout << "\tFAIL t1 < t2 test says true." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tPASS t1 < t2 test says false." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 < t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded < operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue-1, mValue);
            Time t2(hValue, mValue);
            if ( t1 < t2 )
            {
                cout << "\tPASS t1 < t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 < t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 < t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, overloaded < operator, ";
        cout << "getter methods..." << endl;
        try
        {
            int hValue = 20, mValue = 19;
            Time t1(hValue, mValue-1);
            Time t2(hValue, mValue);
            if ( t1 < t2 )
            {
                cout << "\tPASS t1 < t2 test says true." << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL t1 < t2 test says false." << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
            }
        }
        catch (...)
        {
            cout << "\tFAIL t1 < t2 test throws." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, invalid values..." << endl;
        try
        {
            Time t1(MIN_HOUR-1, MIN_MINUTE);

            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, invalid values..." << endl;
        try
        {
            Time t1(MIN_HOUR, MIN_MINUTE-1);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, invalid values..." << endl;
        try
        {
            Time t1(MAX_HOUR+1, MAX_MINUTE);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, invalid values..." << endl;
        try
        {
            Time t1(MAX_HOUR, MAX_MINUTE+1);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, setTime with invalid values..." << endl;
        try
        {
            Time t1;
            t1.setTime(MIN_HOUR-1, MIN_MINUTE);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, setTime with invalid values..." << endl;
        try
        {
            Time t1;
            t1.setTime(MIN_HOUR, MIN_MINUTE-1);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, setTime with invalid values..." << endl;
        try
        {
            Time t1;
            t1.setTime(MAX_HOUR+1, MAX_MINUTE);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, setTime with invalid values..." << endl;
        try
        {
            Time t1;
            t1.setTime(MAX_HOUR, MAX_MINUTE+1);
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, ";
        cout << "overloaded stream extraction operator, getter methods..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 59;
            int hValue2 = 24, mValue2 = 0;
            int hValue3 = 3, mValue3 = 15;
            
            // use string stream to convert int time components to a string
            ostringstream out;
            out << hValue1 << ":" << mValue1 << " ";
            out << hValue2 << ":" << mValue2 << " ";
            out << hValue3 << ":" << mValue3 << "\n";
            
            string inputDates = out.str();
            
            Time t1, t2, t3;
            
            istringstream in(inputDates);
            cout << "input stream: " << inputDates << endl;
            
            in >> t1 >> t2 >> t3;
            
            if ( t1.getHour() == hValue1 && t1.getMinute() == mValue1 &&
                 t2.getHour() == hValue2 && t2.getMinute() == mValue2 &&
                 t3.getHour() == hValue3 && t3.getMinute() == mValue3 )
            {
                cout << "\tPASS operator>>" << endl; passCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
                cout << "\tt3 hour: " << t3.getHour() << " minute: " << t3.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL operator>>" << endl; failCount++;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
                cout << "\tt3 hour: " << t3.getHour() << " minute: " << t3.getMinute() << endl;
            }
            
        }
        catch (...)
        {
            cout << "\tFAIL test of operator>> incorrectly throws exception" << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, ";
        cout << "overloaded stream extraction operator, getter methods..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 60;  // invalid minute
            int hValue2 = 23, mValue2 = 9;
            int hValue3 = 3, mValue3 = 15;
            
            // use string stream to convert int time components to a string
            ostringstream out;
            out << hValue1 << ":" << mValue1 << " ";
            out << hValue2 << ":" << mValue2 << " ";
            out << hValue3 << ":" << mValue3 << "\n";
            
            string inputDates = out.str();
            
            Time t1, t2, t3;
            
            istringstream in(inputDates);
            cout << "input stream: " << inputDates << endl;
            
            in >> t1 >> t2 >> t3;
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
            
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS throws invalid_argument." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, ";
        cout << "overloaded stream extraction operator, getter methods..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 19;
            int hValue2 = 23, mValue2 = 9;
            int hValue3 = 25, mValue3 = 15;   // invalid hour
            
            // use string stream to convert int time components to a string
            ostringstream out;
            out << hValue1 << ":" << mValue1 << " ";
            out << hValue2 << ":" << mValue2 << " ";
            out << hValue3 << ":" << mValue3 << "\n";
            
            string inputDates = out.str();
            
            Time t1, t2, t3;
            
            istringstream in(inputDates);
            cout << "input stream: " << inputDates << endl;
            
            in >> t1 >> t2 >> t3;
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
            
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS throws invalid_argument." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, ";
        cout << "overloaded stream extraction operator, getter methods..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 19;
            int hValue2 = 23, mValue2 = 9;
            int hValue3 = 24, mValue3 = 1;   // invalid minute for hour 24
            
            // use string stream to convert int time components to a string
            ostringstream out;
            out << hValue1 << ":" << mValue1 << " ";
            out << hValue2 << ":" << mValue2 << " ";
            out << hValue3 << ":" << mValue3 << "\n";
            
            string inputDates = out.str();
            
            Time t1, t2, t3;
            
            istringstream in(inputDates);
            cout << "input stream: " << inputDates << endl;
            
            in >> t1 >> t2 >> t3;
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
            
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS throws invalid_argument." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class default constructor, ";
        cout << "overloaded stream extraction operator, failed stream..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 19;
            int hValue2 = 23, mValue2 = 9;
            int hValue3 = 2, mValue3 = 1;
            
            // use string stream to convert int time components to a string
            ostringstream out;
            out << hValue1 << ":" << mValue1 << " ";
            out << hValue2 << ":" << mValue2 << " ";
            out << hValue3 << ":" << mValue3 << "\n";
            
            string inputDates = out.str();
            
            Time t1, t2, t3;
            
            istringstream in(inputDates);
            cout << "input stream: " << inputDates << endl;
            
            in >> t1;
            in >> t2;
            in.setstate(ios::failbit);
            in >> t3;
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
            
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS throws invalid_argument." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
     
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, ";
        cout << "overloaded stream insertion operator..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 59;
            int hValue2 = 24, mValue2 = 0;
            int hValue3 = 3, mValue3 = 15;
            
            ostringstream strm1, strm2, strm3;
            
            // use string stream to test steam insertion operator
            ostringstream out;
            
            Time t1(hValue1, mValue1), t2(hValue2, mValue2), t3(hValue3, mValue3);
            
            out << t1 << " " << t2 << " " << t3 << "\n";
            
            string result = out.str();
            
            bool found1 = (result.find("20:59") != string::npos);
            bool found2 = (result.find("24:00") != string::npos);
            bool found3 = (result.find("03:15") != string::npos);
            
            if ( found1 && found2 && found3 )
            {
                cout << "\tPASS operator<<" << endl; passCount++;
                cout << "\tresult: " << result << endl;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
                cout << "\tt3 hour: " << t3.getHour() << " minute: " << t3.getMinute() << endl;
            }
            else
            {
                cout << "\tFAIL operator<<" << endl; failCount++;
                cout << "\tresult: " << result << endl;
                cout << "\tt1 hour: " << t1.getHour() << " minute: " << t1.getMinute() << endl;
                cout << "\tt2 hour: " << t2.getHour() << " minute: " << t2.getMinute() << endl;
                cout << "\tt3 hour: " << t3.getHour() << " minute: " << t3.getMinute() << endl;
            }
            
        }
        catch (...)
        {
            cout << "\tFAIL test of operator<< incorrectly throws exception" << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        //
        // NEXT TEST
        //
        cout << setw(w1) << tSpacer << setw(w2) << ++testCount << endl << setw(w1) << tSpacer;
        cout << endl;
        
        cout << "testing Time class constructor with parameters, ";
        cout << "overloaded stream insertion operator, failed stream..." << endl;
        try
        {
            int hValue1 = 20, mValue1 = 59;
            int hValue2 = 24, mValue2 = 0;
            int hValue3 = 3, mValue3 = 15;
            
            ostringstream strm1, strm2, strm3;
            
            // use string stream to test steam insertion operator
            ostringstream out;
            
            Time t1(hValue1, mValue1), t2(hValue2, mValue2), t3(hValue3, mValue3);
            
            out << t1 << " ";
            out << t2 << " ";
            out.setstate(ios::failbit);
            out << t3 << "\n";
            
            cout << "\tFAIL should have throw exception." << endl; failCount++;
            
        }
        catch (invalid_argument &e)
        {
            cout << "\tPASS throws invalid_argument." << endl << "\t" << e.what(); passCount++;
        }
        catch (...)
        {
            cout << "\tFAIL should throw invalid_argument." << endl; failCount++;
        }
        cout << "End test.\n" << endl;
        
        
        
        
        cout << endl;
        cout << setw(w1) << tSpacer << setw(w2+4) << "Test Summary" << endl << setw(w1) << tSpacer;
        cout << fixed << setprecision(2) << showpoint;
        cout << setw(c1) << static_cast<double>(testCount);
        cout << setw(c2) << left << "    total tests" << right << endl;
        cout << setw(c1) << static_cast<double>(passCount);
        cout << setw(c2) << left << "    total pass" << right << endl;
        cout << setw(c1) << static_cast<double>(failCount);
        cout << setw(c2) << left << "    total fail" << right << endl;
        
        cout << setw(w1) << tSpacer;
        
        cout << setw(c1) << 100 * (passCount/(static_cast<double>(testCount)));
        cout << setw(c2) << left << "    % passed" << right << endl;
       
        cout << setw(w1) << tSpacer << endl << endl;
        
        
        //*/