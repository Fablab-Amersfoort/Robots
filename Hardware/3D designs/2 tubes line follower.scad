$fn = 20;
difference() {
translate([-40,-10,0]) cube([80,25,1]);
    {
    translate([-15,0,0]) cylinder(r=3, h=1);
    translate([15,0,0]) cylinder(r=3, h=1);
    translate([0,0,0]) cylinder(r=2.5, h=1);   
    }
}

translate([-15,0,0])
difference() 
{
    cylinder(r=4,h=30);
    cylinder(r=3, h=30);
}
translate([15,0,0])
difference() 
{
    cylinder(r=4,h=30);
    cylinder(r=3, h=30);
}

