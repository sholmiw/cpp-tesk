//
// Created by shosh on 4/9/18.
//

#ifndef UNTITLED1_MEMBER_H
#define UNTITLED1_MEMBER_H
#include <iostream>
#include <set>


//static int counter;

class Member {
    std::set<Member*> myfollower;
    std::set<Member*> ifollowing;
    static int counter;
public:
    Member();
    void follow(Member &x);
    void unfollow(Member &x);
    //static int counter;

    static int count() {return counter;};
    int numFollowers() const {return myfollower.size();};
    int numFollowing() const {return ifollowing.size();};
    // int& numFollowers();
    // int& numFollowing();
    ~Member();
};

#endif //UNTITLED1_MEMBER_H
