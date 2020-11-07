function [Wh,Wk] = backprop(X,y1,y2,maxIter,eta)
	[m n]=size(X);
	
	% initialize weights
	h=3;	% number of hidden layers
	k=2;	% number of output layers 
	
	% hiden layer weights (n+1)*h
	epsilon=0.1;	
	Wh=rand(n+1,h)* 2 * epsilon - epsilon
	Wk=rand(h+1,k)*2 * epsilon - epsilon
	
	
	
for iter=1:maxIter
	
	for i=1:m
		% step 1: forward propagation
		% add 1 as a bias feature
		iX=X(i,:);
		changedX=[1 iX];
		hOut=sigmoid(changedX*Wh);
		changedH=[1 hOut];
		kOut = sigmoid(changedH*Wk);
        % end of forward propagation
		
		%step 2: find delta for output layer
		
		delK=kOut(1)*(1-kOut(1))*(y1(i)-kOut(1));
        delK1=kOut(2)*(1-kOut(2))*(y2(i)-kOut(2));
        
        
		Wk(1,1)=Wk(1,1)+eta*delK*changedH(1);
		Wk(2,1)=Wk(2,1)+eta*delK*changedH(2);
		Wk(3,1)=Wk(3,1)+eta*delK*changedH(3);
        Wk(4,1)=Wk(4,1)+eta*delK*changedH(4);
		
        Wk(1,2)=Wk(1,2)+eta*delK1*changedH(1);
		Wk(2,2)=Wk(2,2)+eta*delK1*changedH(2);
		Wk(3,2)=Wk(3,2)+eta*delK1*changedH(3);
        Wk(4,2)=Wk(4,2)+eta*delK1*changedH(4);
		
        
		%step 3: find delta for hidden layer
		
        s1=Wk(2,1)*delK+Wk(2,2)*delK1;
        
		delH(1)=hOut(1)*(1-hOut(1))*s1;
        s2=Wk(3,1)*delK+Wk(3,2)*delK1;
        
		delH(2)=hOut(2)*(1-hOut(2))*s2;
        s3=Wk(4,1)*delK+Wk(4,2)*delK1;
        
        delH(3)=hOut(3)*(1-hOut(3))*s3;
				
		%step 4: update weights
		
		Wh(1,1)=Wh(1,1)+eta*delH(1)*changedX(1);
		Wh(2,1)=Wh(2,1)+eta*delH(1)*changedX(2);
		Wh(3,1)=Wh(3,1)+eta*delH(1)*changedX(3);
        Wh(4,1)=Wh(4,1)+eta*delH(1)*changedX(4);
		
		Wh(1,2)=Wh(1,2)+eta*delH(2)*changedX(1);
		Wh(2,2)=Wh(2,2)+eta*delH(2)*changedX(2);
		Wh(3,2)=Wh(3,2)+eta*delH(2)*changedX(3);
        Wh(4,2)=Wh(4,2)+eta*delH(2)*changedX(4);
        
        Wh(1,3)=Wh(1,3)+eta*delH(3)*changedX(1);
		Wh(2,3)=Wh(2,3)+eta*delH(3)*changedX(2);
		Wh(3,3)=Wh(3,3)+eta*delH(3)*changedX(3);
        Wh(4,3)=Wh(4,3)+eta*delH(3)*changedX(4);
        

	end

end

sigmoid([ones(m,1) sigmoid([ones(m,1) X]*Wh)]*Wk)
end
