$fn = 20;
$height = 3;
difference() {
translate([-40,-10,0]) cube([80,25,$height]);
    {
    translate([-15,0,0]) cylinder(r=3, h=$height);
    translate([15,0,0]) cylinder(r=3, h=$height);
    translate([0,0,0]) cylinder(r=2.5, h=$height);   
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

