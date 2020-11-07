function c = k_means(k)
    x=[1 1 1.5 2 2 1 2 2.5 3 4 5 5 5.5 5.5 5 6 6];
    y=[1 2 1.5 1 2 3 3 2.5 2 4 3 4 3.5 4.5 5 4 5];

    data = [x;y] % copy all data to a matrix named 'data'

    %k=2; % no of cluster 2
    center = data(:,1:k) % center will be two..1st one is (1 1)..2nd one is (1 2)
    plot(x,y,'*','MarkerSize',10);
    axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5

    hold on

    plot(center(1,:),center(2,:),'rs','MarkerSize',10);
   
    hold off
   
    [r numData] = size(data);
   
    oldcenter = zeros(size(center));
   
    while (1==1)

        %%%%%%%%%%%%%%%%%TASK-1: FIND THE EUCLID DISTANCE FROM EACH CENTER
        %  And store the distances in a matrix namely d 
   
            disp('distance array');
        for i=1:k
            for j=1:numData
               
             d(i,j)=EuclidDist(center(1,i),data(1,j),center(2,i),data(2,j));
            end
           
        end
        disp('distance array');
        d





        c=zeros(size(d)); 
        %step 1
        % min (d(:,1))
        l=1;
        m=1;
        p=1;
        q=1;
        for j=1:numData
          
            if d(1,j)< d(2,j)
               c(1,j)=1;
               x1(l)=x(j);
               y1(m)=y(j);
               l=l+1;
               m=m+1;
       
           else
               c(2,j)=1;
               x2(p)=x(j);
               y2(q)=y(j);
               p=p+1;
               q=q+1;
           
           end
          
        end
        %step 2
        %find (d(:,1)==min (d(:,1)));
       
        %final step
        %c(find (d(:,1)==min (d(:,1))), 1) =1;
     
    %%%%%%%%%%%%%%%%%TASK-2: FIND THE MINIMUM VALUED INDEX FROM d MATRIX
    % AND PLACE 1 ON THAT INDEX OF C MATRIX
 
 

 
 
 



        %%%%%%%%%%%%%%%%%TASK-3: MAKE GROUP BASED ON 1 ON C MATRIX (USE groupIndex FUNCTION)
       
       


       


    % new center
        oldcenter = center;       
        %%%%%%%%%%%%%%%%%%TASK-4: NEW CENTER CALCULATION FROM groupIndex VECTOR
       
        for i=1:k
        groupIndex{i}=find(c(i,:)==1);
        end
     
           for i=1:k
            t=data(:,groupIndex{i});
            cx=sum(t(1,:));
            cy=sum(t(2,:));
            [r1 c1]=size(t);
            center(1,i)=cx/c1;
            center(2,i)=cy/c1;
       
           end
   
           disp('Center array');
               center
       
 


       
        plot(x,y,'*','MarkerSize',10);
        axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5

        hold on

        plot(center(1,:),center(2,:),'rs','MarkerSize',10);
   
        hold off
   
        pause(1);
        if(center==oldcenter)
            break;
        end
       
    end
    %start of naive biase
        [r col]=size(data);
        col
       
        for i=1:k
        count=0;
          for j=1:col
          
             if(c(i,j)==1)
               count=count+1;
              end
         
          end
       
         probprior(i)=count/col;
        end
      % disp('hellooo');
   
       
        newcenter=[3.5;2.5];
         plot(x1,y1,'*','color','green','MarkerSize',10);
         axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5
         hold on 
         plot(x2,y2,'*','color','blue','MarkerSize',10);
         axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5
         
        hold off
        
        hold on

        plot(newcenter(1,:),newcenter(2,:),'rs','color','red','MarkerSize',10);
   
        hold off
        pause(1);
             
            newcount(1:2)=0;
           
            for j=1:col
               
               distance(j)=EuclidDist(newcenter(1,1),data(1,j),center(2,1),data(2,j));
                 
               if(distance(j)<=2)
                      if(c(1,j)==1)
                         newcount(1)=newcount(1)+1;
                      else
                          newcount(2)=newcount(2)+1;
                      end
                  
                      
                   end
            end
            distance
            newcount
        for i=1:k
        count=0;
          for j=1:col
          
             if(c(i,j)==1)
               count=count+1;
              end
         
          end
       
         likelyhood(i)=newcount(i)/count;
         count=0;
        end
            for i=1:k
               posterior_prob(i)=probprior(i)*likelyhood(i);
            end
        posterior_prob
        val=max(posterior_prob)
        for i=1:size(posterior_prob)
           if(posterior_prob(i)==val)
              disp('Group');
              disp(i);
              break;
           end
        end
        if(i==1)
            
         plot(x1,y1,'*','color','green','MarkerSize',10);
         axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5
         hold on 
         plot(x2,y2,'*','color','blue','MarkerSize',10);
         axis([0 6.5 0 5.5]) % x axis range will be 0 to 6.5
         
        hold off
        
        hold on

        plot(newcenter(1,:),newcenter(2,:),'rs','color','green','MarkerSize',10);
   
        hold off
        else
         plot(x1,y1,'*','color','green','MarkerSize',10);
         axis([0 10 0 10]) % x axis range will be 0 to 6.5
         hold on 
         plot(x2,y2,'*','color','blue','MarkerSize',10);
         axis([0 10 0 10]) % x axis range will be 0 to 6.5
         
        hold off
        
        hold on

        plot(newcenter(1,:),newcenter(2,:),'rs','color','blue','MarkerSize',10);
   
        hold off
            
        end
       
end