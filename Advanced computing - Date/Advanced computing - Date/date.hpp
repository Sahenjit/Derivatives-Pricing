//
//  date.hpp
//  Advanced computing - Date
//
//  Created by Shankar on 03/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef date_hpp
#define date_hpp

enum Weekday{SUNDAY=1,MONDAY=2,TUESDAY=2,WEDNESDAY=3,THURSDAY=4,FRIDAY=5,SATURDAY=6};
class Date
{
public:
    Date(unsigned int d,unsigned int m, unsigned int y);
    void addDays(int d);
    void addMonths(int m);
    void addYear(int y);
    double Daysdiff(Date dt);
    void getDMY(unsigned int &d,unsigned int &m, unsigned int &y);
    Weekday weekday();
    bool IsGbd();
private:
    
    unsigned int m_serial;
};
#endif /* date_hpp */
