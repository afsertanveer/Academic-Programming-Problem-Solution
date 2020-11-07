function astar(stateInitial)
% this function will take the nodeInitial and return steps as a vector of
% steps here 0=UP 1= DOWN 2=RIGHT 3=LEFT 

%set up the initialnode

steps=[];

field1='state';
field2='steps';
field3='cost';
value1=stateInitial;
value2=[];
value3=0;
initialNode=struct(field1,value1,field2,value2,field3,pathCostGx(stateInitial)+manhattanDistance(stateInitial));
frontier=[initialNode];
closedList=[];
success=0;
%while length(frontier)~=0
    % sort the frontier according to g(x)+h(x) or move the element with the smallest value to the top
    while length(frontier) > 0 
           
        x=frontier.state;
        
     if(success==0)
        disp('Innitial State:' );
        disp(x(1:3:9));
        
        disp(x(2:3:9));
        disp(x(3:3:9));
         
         
         
     end
        
    min=frontier(1).cost;
    i=1;
    counter=1;
   while i<=length(frontier)
        if frontier(i).cost<min
            min=frontier(i).cost;
            counter=i;
        end
        i=i+1;
   end
   
    % extract a solution from top
    
    temp=frontier(counter);
    frontier(counter)=frontier(1);
    frontier(1)=temp;
    front=frontier(1); 
    
    %delete it
    
    frontier=frontier(2:end);
    
    % goal check
    
    if goalCheck(front.state) == 1
        steps=front.steps;
        for q=1:length(steps)
            
           if(steps(q)==3)
                disp('Left');
           end
           
           if(steps(q)==2)
                disp('Right');
           end
           
           if(steps(q)==1)
                disp('Down');
           end
           
           if(steps(q)==0)
                disp('UP');
           end
           
            
        end
        break;
    end
    
    % now expand and add the children to the frontier
    
    closedList=[closedList front];
    
    upChild=up(front.state);
    if sum(upChild == [0 0 0 0 0 0 0 0 0])~= 9
        % here we add the steps to the child and create  a node
       upNode=struct(field1,upChild,field2,[front.steps 0],field3,pathCostGx([front.steps 0])+manhattanDistance(upChild));
       
       if checkClosedList(closedList,upNode) == 0
          frontier = [frontier upNode];
            x=upNode.state;
        disp('Current State in Frontier:' );
        disp(x(1:3:9));
        
        disp(x(2:3:9));
        disp(x(3:3:9));
        
       end
    end
    
    
    
    downChild=down(front.state);
    if sum(downChild == [0 0 0 0 0 0 0 0 0])~= 9
        % here we add the steps to the child and create  a node
       downNode=struct(field1,downChild,field2,[front.steps 1],field3,pathCostGx([front.steps 1])+manhattanDistance(downChild));
       if checkClosedList(closedList,downNode) == 0
           frontier = [frontier downNode];
       
            x=downNode.state;
        disp('Current State in Frontier:' );
        disp(x(1:3:9));
        
        disp(x(2:3:9));
        disp(x(3:3:9));
       
       end
    end
    
    
    leftChild=left(front.state);
    if sum(leftChild == [0 0 0 0 0 0 0 0 0])~= 9
        % here we add the steps to the child and create  a node
       leftNode=struct(field1,leftChild,field2,[front.steps 3],field3,pathCostGx([front.steps 3])+manhattanDistance(leftChild));
       if checkClosedList(closedList,leftNode) == 0         
           frontier = [frontier leftNode];
        x=leftNode.state;
        disp('Current State in Frontier:' );
        disp(x(1:3:9));
        
        disp(x(2:3:9));
        disp(x(3:3:9));
       
       end
    end
    
    rightChild=right(front.state);
    if sum(rightChild == [0 0 0 0 0 0 0 0 0])~= 9
        % here we add the steps to the child and create  a node
       rightNode=struct(field1,rightChild,field2,[front.steps 2],field3,pathCostGx([front.steps 2])+manhattanDistance(rightChild));
       if checkClosedList(closedList,rightNode) == 0
           frontier = [frontier rightNode];
                 x=rightNode.state;
        disp('Current State in Frontier:' );
        disp(x(1:3:9));
        
        disp(x(2:3:9));
        disp(x(3:3:9));
       
       end
    end
    end
%end
end
