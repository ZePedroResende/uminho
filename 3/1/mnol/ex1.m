function [f] = ex1(x)
  f=(x-1) * exp(x) - x - 17 ;
end
%x = fsolve('ex1',2)
%x = fsolve('ex1',2)
%[x,f,exitflag,output] = fsolve('ex1',2)
%optimset fsolve
%options = optimset('display','iter')
%options=optimset('display','iter','tolx',1.0e-10,'tolfun',1.0e-9)
%[x,f,exitflag,output] = fsolve('ex1',2,options)
