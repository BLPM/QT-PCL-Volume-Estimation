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

for i = 1:slicecount
    
    
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
