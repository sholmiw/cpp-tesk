//
// Created by shosh on 4/9/18.
//

#include "Member.h"

int Member::counter=0;
Member::Member(){
//    std::set<Member*> myfollower;
//    std::set<Member*> ifollowing;
    counter++;
}
void Member::follow (Member &x){
    ifollowing.insert(&x);
    x.myfollower.insert(this);
}
void Member::unfollow(Member &x){
    ifollowing.erase(&x);
    x.myfollower.erase(this);
}
//int Member::numfollowers(){
//    return myfollower.size();
//}
//int  Member::numfolloing(){
//    return ifollowing.size();
//}
//int Member::count(){
//    return counter;
//}
// Member::~Member(){}
Member::~Member(){
    counter--;
		for (Member* x: ifollowing) {
			this->unfollow(*x);
		}
		for (Member* x: myfollower) {
			x->unfollow(*this);
		}
		
	
    
 }
