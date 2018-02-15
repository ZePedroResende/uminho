function [f] = ex2(x)
  f(1)= 70*exp(x(1))+20*exp(x(2))-27.5702;
  f(2)= 70*exp(2*x(1))+20*exp(2*x(2))-17.6567;

  %um = 70*exp(x(1))+20*exp(x(2))-27.5702;
  %dois = 70*exp(2*x(1))+20*exp(2*x(2))-27.5702;

  %f= [um;dois]
end
%[x,f,exitflag,output] = fsolve('ex2',[-1 -0.1])
%[x,f,exitflag,output] = fsolve('ex2',[-1 -0.1],options)


