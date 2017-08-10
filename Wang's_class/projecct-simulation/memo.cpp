

ddx = f_X/m;
ddy = f_y/m;

x = x + dx*dt + ddx * dt * dt/2.0;
y = y + dy*dt + ddy * dt * dt/2.0;
dx = dx + ddx * dt;

