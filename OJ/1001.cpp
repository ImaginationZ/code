#include <cstdio>

int main(){
    int hight,desk,n;
    int postion,nreach=0;
    scanf("%d %d %d",&hight,&desk,&n);
    const int reach = hight + desk;
    for (int i=0;i<n;++i){
        scanf("%d",&postion);
        if (postion <= reach)
            ++nreach;
    }
    printf("%d\n",nreach);
    return 0;
}
