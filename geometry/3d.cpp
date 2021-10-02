const double eps = 1e-8;
int sgn(double x){
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
struct Point3{
	double x,y,z;
	Point3(double _x = 0,double _y = 0,double _z = 0){
		x = _x;
		y = _y;
		z = _z;
	}
	void input(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	void output(){
		printf("%.2lf %.2lf %.2lf\n",x,y,z);
	}
	bool operator ==(const Point3 &b)const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0 && sgn(z-b.z) == 0;
	}
	bool operator <(const Point3 &b)const{
		return sgn(x-b.x)==0 ? (sgn(y-b.y)==0?sgn(z-b.z)<0:y<b.y):x<b.x;
	}
	double len(){
		return sqrt(x*x+y*y+z*z);
	}
	double len2(){
		return x*x+y*y+z*z;
	}
	double distance(const Point3 &b)const{
		return sqrt((x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) + (z-b.z)*(z-b.z));
	}
	Point3 operator -(const Point3 &b)const{
		return Point3(x-b.x,y-b.y,z-b.z);
	}
	Point3 operator +(const Point3 &b)const{
		return Point3(x+b.x,y+b.y,z+b.z);
	}
	Point3 operator *(const double &k)const{
		return Point3(x*k,y*k,z*k);
	}
	Point3 operator /(const double &k)const{
		return Point3(x/k,y/k,z/k);
	}
	//点乘
	double operator *(const Point3 &b)const{
		return x*b.x+y*b.y+z*b.z;
	}
	//叉乘
	Point3 operator ^(const Point3 &b)const{
		return Point3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
	}
	double rad(Point3 a,Point3 b){
		Point3 p = (*this);
		return acos( ( (a-p)*(b-p) ) / (a.distance(p)*b.distance(p)) );
	}
	//变换长度
	Point3 trunc(double r){
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point3(x*r,y*r,z*r);
	}
};
struct Line3
{
	Point3 s,e;
	Line3(){}
	Line3(Point3 _s,Point3 _e)
	{
		s = _s;
		e = _e;
	}
	bool operator ==(const Line3 v)
	{
		return (s==v.s)&&(e==v.e);
	}
	void input()
	{
		s.input();
		e.input();
	}
	double length()
	{
		return s.distance(e);
	}
	//点到直线距离
	double dispointtoline(Point3 p)
	{
		return ((e-s)^(p-s)).len()/s.distance(e);
	}
	//点到线段距离
	double dispointtoseg(Point3 p)
	{
		if(sgn((p-s)*(e-s)) < 0 || sgn((p-e)*(s-e)) < 0)
			return min(p.distance(s),e.distance(p));
		return dispointtoline(p);
	}
	//`返回点p在直线上的投影`
	Point3 lineprog(Point3 p)
	{
		return s+(((e-s)*((e-s)*(p-s))) / ((e-s).len2()));
	}
	//`p绕此向量逆时针arg角度`
	Point3 rotate(Point3 p,double ang)
	{
		if(sgn(((s-p)^(e-p)).len()) == 0)return p;
		Point3 f1 = (e-s)^(p-s);
		Point3 f2 = (e-s)^(f1);
		double len = ((s-p)^(e-p)).len()/s.distance(e);
		f1 = f1.trunc(len); f2 = f2.trunc(len);
		Point3 h = p+f2;
		Point3 pp = h+f1;
		return h + ((p-h)*cos(ang)) + ((pp-h)*sin(ang));
	}
	//`点在直线上`
	bool pointonseg(Point3 p)
	{
		return sgn( ((s-p)^(e-p)).len() ) == 0 && sgn((s-p)*(e-p)) == 0;
	}
};
struct Plane
{
	Point3 a,b,c,o;//`平面上的三个点，以及法向量`
	Plane(){}
	Plane(Point3 _a,Point3 _b,Point3 _c)
	{
		a = _a;
		b = _b;
		c = _c;
		o = pvec();
	}
	Point3 pvec()
	{
		return (b-a)^(c-a);
	}
	//`ax+by+cz+d = 0`
	Plane(double _a,double _b,double _c,double _d)
	{
		o = Point3(_a,_b,_c);
		if(sgn(_a) != 0)
			a = Point3((-_d-_c-_b)/_a,1,1);
		else if(sgn(_b) != 0)
			a = Point3(1,(-_d-_c-_a)/_b,1);
		else if(sgn(_c) != 0)
			a = Point3(1,1,(-_d-_a-_b)/_c);
	}
	//`点在平面上的判断`
	bool pointonplane(Point3 p)
	{
		return sgn((p-a)*o) == 0;
	}
	//`两平面夹角`
	double angleplane(Plane f)
	{
		return acos(o*f.o)/(o.len()*f.o.len());
	}
	//`平面和直线的交点，返回值是交点个数`
	int crossline(Line3 u,Point3 &p)
	{
		double x = o*(u.e-a);
		double y = o*(u.s-a);
		double d = x-y;
		if(sgn(d) == 0)return 0;
		p = ((u.s*x)-(u.e*y))/d;
		return 1;
	}
	//`点到平面最近点(也就是投影)`
	Point3 pointtoplane(Point3 p)
	{
		Line3 u = Line3(p,p+o);
		crossline(u,p);
		return p;
	}
	//`平面和平面的交线`
	int crossplane(Plane f,Line3 &u)
	{
		Point3 oo = o^f.o;
		Point3 v = o^oo;
		double d = fabs(f.o*v);
		if(sgn(d) == 0)return 0;
		Point3 q = a + (v*(f.o*(f.a-a))/d);
		u = Line3(q,q+oo);
		return 1;
	}
};