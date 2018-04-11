//
// Created by shlomiw on 4/9/18.
//

#include "Member.h"

int Member::counter=0;
Member::Member(){
//    std::set<Member*> myfollower; //no need  
//    std::set<Member*> ifollowing;
    counter++;
}
void Member::follow (Member &x){
    if (this==&x) return;
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
// i used this code for the destroctor func, (and also in the h file)
//https://github.com/erelsgl/infinite/commit/e06f26229ea0531b7841f54d388ae4c0bf510d04#diff-5416366bb95630880f3031cf69839b3c

Member::~Member(){
    counter--;
		for (Member* x: ifollowing) {
			this->unfollow(*x);
		}
		for (Member* x: myfollower) {
			x->unfollow(*this);
		}    
 }
