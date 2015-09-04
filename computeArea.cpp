// misunderstanding 
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int leftX= A<E?E:A;
        int rightX = C<G?C:G;
        
        if(leftX > rightX)
            return 0;
            
        int leftY= B<F?F:B;
        int rightY = D<H?D:H;
        if(leftY > rightY)
            return 0;
        
        return (rightX-leftX)*(rightY-leftY);
        
 
    }