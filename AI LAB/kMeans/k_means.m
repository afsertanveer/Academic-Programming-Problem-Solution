function c = k_means(k)
    x=[1 1 1.5 2 2 1 -2 2.5 -3 4 5 5 5.5 5.5 5 6 6];
    y=[1 2 1.5 1 2 3 -3 2.5 2 -4 3 4 3.5 4.5 5 4 5];
    
    data = [x;y] % copy all data to a matrix named 'data' 

    disp('All data');
   % data 
    
    %k=2; % no of cluster 2
    center = data(:,1:k) % center will be two..1st one is (1 1)..2nd one is (1 2) 
    plot(x,y,'*','MarkerSize',10);
    axis([-6 6.5 -6 5.5]) % x axis range will be 0 to 6.5 

    hold on

    plot(center(1,:),center(2,:),'rs','MarkerSize',10);
    
    hold off
    
    %pause(1);
    [r numData] = size(data);
    
    oldcenter = zeros(size(center));
    
    while(true)

        %%%%%%%%%%%%%%%%%TASK-1: FIND THE EUCLID DISTANCE FROM EACH CENTER
        %  And store the distances in a matrix namely d  
    
        for i=1:k
            for j=1:numData
                
             d(i,j)=EuclidDist(center(1,i),data(1,j),center(2,i),data(2,j));
            end
            
        end
        



        c=zeros(size(d));  
        for j=1:numData
           
            if d(1,j)< d(2,j)
               c(1,j)=1;
        
           else
               c(2,j)=1;
            
           end
           
        end
    
       oldcenter = center;        
 
       
           for i=1:k
               counter=1;
     
        
                cx=0;cy=0;
                   for j=1:numData
                        
                       if(c(i,j)==1)
                          cx=cx+data(1,j);
                          cy=cy+data(2,j);
                           counter=counter+1;
                       end
                       if(cx~=0)
                       center(1,i)=cx/(counter-1);
                       center(2,i)=cy/(counter-1);
                       end
                   end
           
           end
        


        
        plot(x,y,'*','MarkerSize',10);
        axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5 

        hold on

        plot(center(1,:),center(2,:),'rs','MarkerSize',10);
    
        hold off
    
        pause(1);
        if(oldcenter == center) 
            break;
        end
    end
end