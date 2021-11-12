function r = thresholdWithAvg(n)

s = sum(sum(n));
[x, y] = size(n);
pixels = x * y;
avr = s / pixels;

for col = 1:y
    for row = 1:x
        if n(row,col) < avr
            r(row,col) = 0;
        else
            r(row,col) = 255;
        end
    end
end