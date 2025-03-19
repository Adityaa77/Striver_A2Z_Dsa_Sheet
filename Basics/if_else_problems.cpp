//if else problem 1
int age;
cin>>age;
cout<<"Enter age-"<<age<<endl;
 if (age>=18){
    cout<<"you are an adult";
 }
 else{
    cout<<"you are not an adult";
 }
 

 //if else problem 2
int marks;
cin>>marks;
cout<<"Marks-"<<marks<<endl;
if (marks<25){
   cout<<"You got F grade";
}
else if(marks<44 & marks>25){
   cout<<"You got E grade";
}
else if(marks<49 & marks>45){
   cout<<"You got D grade";
}
else if(marks<59 & marks>50){
   cout<<"You got C grade";
}
else if(marks<79 & marks>60){
   cout<<"You got B grade";
}
else if(marks<=100 & marks>80){
   cout<<"You got A grade";
}
else if(marks>100){
   cout<<"Error";
}

