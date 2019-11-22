//rbt
//trees

node flipcolor(node n)
{
	n.color="red";
	n.left.color="black"
	n.right.color="black"
	return n;
}
node leftrotate(node n)
{
	t=n.right;
	n.right=t.left;
	t.left=n;
	t.color=n.color1;
	n.color="red";
	return t;
}
node rightrotate(node n)
{
	t=n.left;
	n.left=t.right;
	t.right=n;
	t.color=n.color;
	n.color="red";
	return t;
}
node flipcolor(node n)
{
	n.color="red";
	n.left.color="black";
	n.right.color="black";
	return n;
}
node insert(node n,int key)
{
	if(n==NULL)
		return new node(k);
	if(n.key>key)
		n.left=insert(n.left,key);
	if(n.key<key)
		n.right=insert(n.right,key);
	else
		//do nothing
	if(n.left.color=="black" && n.right.color=="red")
		n=leftrotate(n);
	if(n.left.color=="red" && n.left.left.color=="red")
		n=rightrotate(n);
	if(n.left.color=="red" && n.right.color=="red")
		n=flipcolor(n)
	
	return n;	
}
