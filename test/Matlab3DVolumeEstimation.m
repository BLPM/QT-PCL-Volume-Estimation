ptCloud = pcread('./20cylinder.ply');
pcshow(ptCloud);
C = sortrows(ptCloud.Location,[3,1,2]);
n= 1;
D = zeros(1,3);
Dm= zeros(1,3);
n2= 1;
%{
    埃狡翴
%}
for i = 1:ptCloud.Count
    Lia = ismember(C(i,:),D, 'rows');
    Lib = ismember(C(i,:),Dm, 'rows');
    if  ~Lia && (C(i,2)>0)
        D(n,:)=C(i,:);
        n=n+1;
    elseif ~Lib &&(C(i,2)<0)
        Dm(n2,:)=C(i,:);
        n2=n2+1;
    end
end
%{
    Z禸–Slice_Heightち澄Θ眎
%}
Slice_Height = 0.3;


now_H =D(1,3);
SliceIndex = 0;
tag = 0;
slicemin = uint8(min(D(:,3)));
sec = floor((D(end,3)-slicemin)/Slice_Height)+1;
Slice = zeros(1,sec);
for i = 1:n-1
        w = floor((D(i,3)-slicemin)/Slice_Height)+1;
        D(i,4) = w;  
        Slice(w) = Slice(w)+1;
end
Slicecount = D(end,4);
%璽计场だ
%{
Slicecount2 =1;
Slice2 = zeros(1,1);
now_H =Dm(1,3);
SliceIndex = 0;
tag = 0;
for i = 1:n2-1
    if abs(Dm(i,3)-now_H) < Slice_Height
        Dm(i,4) = Slicecount2;
        SliceIndex = SliceIndex+1;
    elseif abs(Dm(i,3)-now_H) > Slice_Height
        Slice2(Slicecount2) = SliceIndex;
        tag  = i;
        Slicecount2 =Slicecount2+1;
        SliceIndex = 1;
        Dm(i,4) = Slicecount2;
        now_H = Dm(i,3);
    end
    if i==n2-1
       Slice2(Slicecount2) = ((n2)-tag);
    end
end
%}
options = fitoptions('Method', 'LinearLeastSquares');
Dindex = 1;
TEMP2 =zeros(1,3);
q = zeros(1,1);
boxslice = 11;
for i = 1:10
    if Slice(i) == 0
        continue
    end
    boxdata = zeros(boxslice ,2);
    CountPoint = Slice(i)-1;
    TEMP2=D(Dindex:(Dindex+CountPoint),1:2);
    [P,~] = size(TEMP2);
    
    slicedeltaX = abs(max(TEMP2(:,1))-min(TEMP2(:,1)))/10;
    for L = 1:P
       boxnum = floor(((TEMP2(L,1)-min(TEMP2(:,1)))/slicedeltaX)+1);
       if abs(TEMP2(L,2))>boxdata(boxnum,2)
           boxdata(boxnum,:) = TEMP2(L,:);
       end
    end
    SliceData.x = boxdata(:,1);
    SliceData.y = boxdata(:,2);
    [m,z] = size(SliceData.x);
    %plot(SliceData.x,SliceData.y,'.');
    SliceAreaEquation =fit(SliceData.x,SliceData.y,'poly2',options);
    figure
    plot(SliceAreaEquation,SliceData.x,SliceData.y,'.');
    q(i)= integrate(SliceAreaEquation,10,-10) * Slice_Height ;
    
    Dindex = Dindex + Slice(i);
end
%璽计场だ
%{
TEMP3 =zeros(1,3);
qm = zeros(1,1);
Dindex = 1;
for i = 1:Slicecount2
    CountPoint = Slice2(i)-1;
    TEMP3=Dm(Dindex:(Dindex+CountPoint),:);
    [P,~] = size(TEMP3);
    
    SliceDatam.x = TEMP3(:,1);
    SliceDatam.y = TEMP3(:,2);
    
    [m,z] = size(SliceDatam.x);
    %plot(SliceDatam.x,SliceDatam.y,'.');
    
    SliceAreaEquationm =fit(SliceDatam.x,SliceDatam.y,'poly2',options);
    plot(SliceAreaEquation,SliceData.x,SliceData.y,'.');
    qm(i)= integrate(SliceAreaEquationm,SliceData.x,SliceData.y) * Slice_Height ;
    
    Dindex = Dindex + Slice2(i);
end
%}

sum(q)
%sum(qm)
Volume = sum(q);

r = 10;
Truth =pi*(r^2)*10
error =abs((Truth-Volume))/Truth*100


%{
r = 20.014;
Truth =(((4/3)*pi*r^3));
error =abs((Truth-35493.5)/Truth)*100

%}

