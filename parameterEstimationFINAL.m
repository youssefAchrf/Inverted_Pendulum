 J = 0.0000881;
 Kb = 0.0089156;
 Kt = Kb;
 La = 0.057385;
 Ra = 430;
 b = 0.033322;

%jr=0.000055425; 
jr=J;
jp=0.000051301;
mp=0.031;
lr=120*10^(-3);
lp=132*10^(-3);
g=9.81;

c1=jr+mp*(lr^2);
c2=-0.5*mp*lr*lp;
c3=0.25*mp*(lp^2)+jp;
c4=-0.5*mp*lr*lp;
c5=-0.5 *mp*g*lp;
A22= 34^2*(c3*Kt*Kb)/(Ra*(c1*c3-c2*c4));
A23= c2*c5/(c1*c3-c2*c4);
A42= 34^2*c4*Kt*Kb/(Ra*(c1*c3-c2*c4));
A43= -c5/c3;

B2= 34*c3*Kt/(Ra*(c1*c3-c2*c4));
B4=-34*c4*Kt/(Ra*(c1*c3-c2*c4));

A=[0 1 0 0; 0 A22 A23 0;
    0 0 0 1; 0 A42 A43 0];

B= [0; B2; 0; B4];
C=[ 1 0 0 0; 0 0 1 0];
D=[ 0; 0];

% dt = 0.001; % Sampling time
% sys_cont = ss(A,B,C,D); % Continuous-time system
% sys_d = c2d(sys_cont, dt, 'zoh'); % Discrete-time system
% A_d = sys_d.A;
% B_d = sys_d.B;
% C_d = sys_d.C;
% D_d = sys_d.D;
% 
% Q = diag([15,15,0.1,15]); % Weighting matrix for states
% R = 1; % Weighting matrix for control inputs
% [K2, S, e] = dlqr(A_d, B_d, Q, R); % LQR gain matrix


Q =[0.1 0 0 0;
    0 1 0 0;
    0 0 50 0;
    0 0 0 90];

R =0.01; 

[K3,sij,eig] = lqr(A,B,Q,R);
system=ss(A-B*K,B,C,0);
step(system);




