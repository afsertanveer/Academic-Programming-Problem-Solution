function nodeOut=left(nodeIn)
% find the position of 0 and move it up or swap with the element in the
% above position to it 
%If there is not above position then return a zero matrix

nodeOut=nodeIn;          %first copy nodeIn to nodeOut

positionZero=find(~nodeOut);
if positionZero==1 || positionZero==2 || positionZero==3
    nodeOut=zeros(size(nodeIn));
else
    temp=nodeOut(positionZero-3);
    nodeOut(positionZero-3)=0;
    nodeOut(positionZero)=temp;
end
