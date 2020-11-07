function [Wh,Wo]=backPropagation()
% backPropagation(X,y,h,o)
    h = 3;
    o = 1;
    X = [0 0 0; 0 0 1; 0 1 0; 0  1 1; 1 0 0; 1 0 1;];
    y1 = [0;0;1;1;0;0];
    y2 = [0;0;0;1;0;1];
    [m,n]=size(X:2);
    Wh = zeros(n+1,h);
%   wh
    Wo = zeros(h+1,o); 
%   Wo

    Xchanged = [ones(m,1),X];
    
    for i=1:m
        
       Oh = sigmoid(Xchanged(i,:)*Wh);
       ChangedOh = [1 Oh];
       Ok = sigmoid(ChangedOh*Wo)
       
    end    
end