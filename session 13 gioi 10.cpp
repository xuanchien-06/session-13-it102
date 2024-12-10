#include<stdio.h>
//khai bao ham
void displayMenu();
int nhapphantu();
int inmang();
int themphantu();
int suaphantu();
int xoaphantu();
int sapxep();
int timkiem();
int thoat();
int arr[100],n;
//ham main
int main(){
	int choice;
	do{
		displayMenu();
		printf("Moi ban nhap lua chon: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				nhapphantu( );
				break;
			case 2:
				inmang();
				break;	
			case 3:
				themphantu();
				break;
			case 4:
				suaphantu();
				break;
			case 5:
				xoaphantu();
				break;
			case 6:
				sapxep();
				break;
			case 7:
				timkiem();
				break;
			case 8:
				thoat();
				break;
			default :
				printf("lua chon khong hop le");	
		}
	}	
	while(choice!=8);
	return 0;
}

//logic ham
void displayMenu(){
	printf("\nMenu\n");
	printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
	printf("2.In ra gia tri cac phan tu  dang quan ly\n");
	printf("3.Them mot phan tu vao vi tri chi dinh\n");
	printf("4.Sua mot phan tu o vi tri chi dinh\n");
	printf("5.Xoa mot phan tu o vi tri chi dinh\n");
	printf("6.Sap xep cac phan tu(khi lua chon menu cha thi hien thi menu con)\na.Giam dan\nb.Tang dan\n");
	printf("7.Tim kiem phan tu nhap vao\na.Tim kiem tuy tinh\nb.Tim kiem nhi phan\n");
	printf("8.Thoat\n");
}
//case 1:
int nhapphantu(){
	printf("Nhap vao so luong phan tu: ");
	scanf("%d",&n);
	printf("nhap vao gia tri phan tu:\n");
	for(int i=0 ; i<n ; i++){
		printf("Phan tu thu %d = ",i+1);
		scanf("%d",&arr[i]);
	}
}
//case 2:
int inmang(){
	
	printf("Gia tri cac phan tu trong mang:\n");
	for(int i=0 ; i<n ; i++){
		printf("arr[%d] = %d\n",i,arr[i]);
	}
	
}
//case 3:
int themphantu(){
	int vitri,giatri;
	printf("Nhap vi tri muon them: ");
	scanf("%d",&vitri);
	printf("Nhap gia tri muon them: ");
	scanf("%d",&giatri);
	if(vitri<0 || vitri>n){
		printf("Vi tri khong hop le");
	}else{
		for(int i=n ; i>vitri ; i--){
			arr[i]=arr[i-1];
		}
		arr[vitri]=giatri;
		n++;
	}
	for(int i=0 ; i<n ; i++){
		printf("%d\t",arr[i]);
	}
}
//case 4:
int suaphantu(){
	int vitri,giatri;
	printf("Nhap vi tri muon sua: ");
	scanf("%d",&vitri);
	printf("Nhap gia tri moi: ");
	scanf("%d",&giatri);
	if(vitri<0 || vitri>n){
		printf("Vi tri khong hop le");
	}else{
		arr[vitri]=giatri;
		for(int i=0 ; i<n ; i++){
			printf("%d",arr[i]);	
		}
	}	
}
//case 5:
int xoaphantu(){
	int vitri;
	printf("Nhap vi tri muon xoa: ");
	scanf("%d",&vitri);
	if(vitri<0 || vitri>n){
		printf("Vi tri khong hop le ");
	}	
	for(int i=vitri ; i<n-1 ; i++){
		arr[i]=arr[i+1];
	}
	n--;
	for(int i=0 ; i<n ; i++){
		printf("%d\t",arr[i]);
	}
}
//case 6:
int sapxep(){
	//tang dan
	for (int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}	
	printf("Mang tang dan: ");
	for(int i=0 ;i<n;i++){
		printf("%3d",arr[i]);
	}
	printf("\n");
	//giam dan
	for (int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}	
	printf("Mang giam dan: ");
	for(int i=0 ;i<n;i++){
		printf("%3d",arr[i]);
	}		
}
//case 7: ???????????
int timkiem(){
	int x,vitri=0;
	printf("Nhap gia tri can tim: ");
	scanf("%d",&x);
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			printf("Phan tu %d o vi tri: %d",x,i);
			vitri=1;
			break;	
		}
	}
	if(vitri=0){
		printf("khong tim thay phan tu");
	}
}
//case 8:
int thoat(){
	printf("Thoat");	
}
				
