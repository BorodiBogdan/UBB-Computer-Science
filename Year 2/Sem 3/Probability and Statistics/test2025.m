clc
clear All

X1 = [4.6 0.7 4.2 1.9 4.8 6.1 4.7 5.5 5.4]
X2 = [2.5 1.3 2.0 1.8 2.7 3.2 3.0 3.5 3.4]

% for computations
n1 = length(X1);
n2 = length(X2);
v1 = var(X1);
v2 = var(X2);
m1 = mean(X1);
m2 = mean(X2);

% 1% significance level
alpha = 0.01;

% H0: sigma1 = sigma2
% H1 sigma1 != sigma2 - two-tailed test

% we have to test the variances of the 2 populations, and we know both
% sigma, so we will use vartest2

[h, p, ci, stats] = vartest2(X1, X2, 'Alpha', alpha, 'Tail', 'both');

fprintf('point a)\n');

if h == 0
    fprintf('H0 is not rejected, i.e, sigmas are equal\n');
else
    fprintf('H0 is rejected, population variances differ \n');
end

%because we have a two tailed test
q1 = finv(alpha / 2, stats.df1, stats.df2);
q2 = finv(1 - alpha / 2, stats.df1, stats.df2);

fprintf('Observed value is %1.4f\n', stats.fstat);
fprintf('P-value is %1.4f\n', p);
fprintf('Rejection region R is (-inf, %3.4f) U (%3.4f, inf)\n', q1, q2);

%h = 1 -> we do the calculations below to find the confidence interval
%h0 is rejected so we use the computations below

c = (v1/n1)/(v1/n1 + v2/n2);
n = c ^ 2 / (n1-1) + (1-c) ^ 2/ (n2 - 1);
n = 1/n;
t = tinv(1 - alpha/2, n);
left = m1 - m2 - t * sqrt(v1/n1 + v2/n2);
right = m1 - m2 + t * sqrt(v1/n1 + v2/n2);

fprintf("\nb)\n");
fprintf("The 99 confidence interval is: (%f, %f)\n", left, right);

