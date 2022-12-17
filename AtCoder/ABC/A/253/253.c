#include<stdio.h>

int max=-1, min=(1<<21), median, vec[3];

int main(){
    for(int i=0; i<3; i++) scanf("%i", &vec[i]);
    median = vec[1];

    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){
            if(vec[i] > vec[j]){
                int buf = vec[i];
                vec[i] = vec[j];
                vec[j] = buf;
            }
        }
    }
    if(median == vec[1]) printf("Yes\n");
    else printf("No\n");
    return 0;
}