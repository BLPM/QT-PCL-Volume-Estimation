ptCloud = pcread('./sphere2x2.ply');
[C,index] = sortrows(ptCloud.Location,[3,1,2]);
n = 0;

post_ = 0;

pre_ = 0;

slicecount = 0;
Sliceindex = 0;
Slice = zeros(1,1);
n= 1;
D = zeros(1,3);

for i = 1:ptCloud.Count
    Lia = ismember(C(i,:),D, 'rows');
    if  ~Lia && (C(i,2)>0)
        D(n,:)=C(i,:);
        n=n+1;
    end
end

pcshow(D);
Slice_Area = 0;
SliceVolume = zeros(1,slicecount);
now_ =D(1,3);

for i = 1:n-1
    if D(i,3) ~= now_
        now_ = D(i,3);
        slicecount  = slicecount + 1;
        Slice(slicecount)= Sliceindex;
        Sliceindex = 1;
    elseif D(i,3) == now_
        Sliceindex = Sliceindex +1 ;
    end
end


%{
    Calculate Slice Area
%}

PointCount =0;
frameCount = 1;
Ztemp = 0;
t = 1;
q = zeros(2,1);
Zindex = 1;
TEMP = zeros(1,2);
SliceData.x =zeros(1,1);
SliceData.y =zeros(1,1);

TEMP2 =zeros(1,2);
TEMP3 =zeros(1,2);

for i = 1:20
    PointCount = PointCount+Slice(i);
    Ztemp = Ztemp + D(t,3);
    frameCount = frameCount+1;
    
    if PointCount < 40
        continue
    end
    
    TEMP(1:PointCount+1,1) = D(t:t+PointCount,1);
    TEMP(1:PointCount+1,2) = D(t:t+PointCount,2);
    
    
    [TempSort,index] = sortrows(TEMP,[1,2]);
    
    [O,~] = size(TempSort);
    l=0;
    for k = 1:O
        [Lia,Locb] = ismember(TempSort(k,1),TEMP2(:,1));
        if ~Lia 
            l=l+1;
            TEMP2(l,:) =TempSort(k,:);
        elseif Lia && (TempSort(k,2)>TEMP2(Locb,2))
            TEMP2(Locb,:)=TempSort(k,:);
        else
            continue
        end
    end
    T = TEMP2(:,2);
    Ts = smooth(T,3);
    [Tsw,~] = size(Ts)
    figure;
    plot(1:Tsw,Ts,'.');
    %{
    [P,~] = size(TEMP2);
    for j = 1:P
        if TEMP2(j)-TEMP2(j-1)
        
    end
    %}
    
    %{
    SliceData.x = TEMP2(:,1);
    SliceData.y = TEMP2(:,2);
    SliceData.Zposition = Ztemp/frameCount;
    
    [m,z] = size(SliceData.x);
    Inflection = 0;
    
    for j = 1:m
        if j >m-2 
            continue
        else
            now = sign(SliceData.y(j+1)-SliceData.y(j));
            pre = sign(SliceData.y(j+2)-SliceData.y(j+1));
            if now ~= pre 
                Inflection  =Inflection +1;
            end
        end

    end
    if Inflection >8
       Inflection = 8;
    end
    Equation =fit(SliceData.x,SliceData.y,'poly2');
    %Equation =fit(SliceData.x,SliceData.y,strcat('poly',int2str(Inflection+1)));
    q(1,Zindex)= integrate(Equation,SliceData.x(m),SliceData.x(1));
    q(2,Zindex)= SliceData.Zposition;
 %}
    
    t= t+PointCount;
    PointCount = 0;
    Ztemp =0;
    frameCount = 1;
    Zindex = Zindex+1;
end

%{
[G,Gh] = size(q);
q=q';
Equation2 =fit(q(:,2),q(:,1),'poly2');
plot(Equation2,q(:,2),q(:,1),'.');
Volume = double(integrate(Equation2,ptCloud.ZLimits(2),ptCloud.ZLimits(1)));

r = 20.014;
Truth =(((4/3)*pi*r^3)/2);
error =abs((Truth-Volume)/Truth)*100
Ex = SliceData.x;
Ey = SliceData.y;
%}

