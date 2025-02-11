$width=35;
$height=45;
$deltax=30;
$deltay=47;
$deltaz=0;
$thickness=5;
$hole_diameter=2;
{
    difference() {
            difference()
            {
                translate([-50,-50,-30]) cube([100,100,$thickness]);
                translate([-21,-21,-30]) cube([42,42,5]);
            }
            {
                translate([37,0,-30]) rotate([0,0,0]) cylinder(r=$hole_diameter, h=$thickness);
                translate([-37,0,-30]) rotate([0,0,0]) cylinder(r=$hole_diameter, h=$thickness);
                translate([0,37,-30]) rotate([0,0,0]) cylinder(r=$hole_diameter, h=$thickness);
                translate([0,-37,-30]) rotate([0,0,0]) cylinder(r=$hole_diameter, h=$thickness);
            }
        }

    difference()
    {
        difference()
        {
            cube([46,46,50], center = true);
            cube([42,42,50], center = true);
        }
        {
        translate([0,21,0]) rotate([-90,0,0]) cylinder(r=$hole_diameter, h=2);
        translate([-21,0,0]) rotate([0,-90,0]) cylinder(r=$hole_diameter, h=2);
        translate([0,-21,0]) rotate([90,0,0]) cylinder(r=$hole_diameter, h=2);
        translate([21,0,0]) rotate([0,90,0]) cylinder(r=$hole_diameter, h=2);
        }
    }
}



translate([0,0,-72])
{
{
    rotate([90,0,45])
    translate([$deltax,$deltay,$deltaz])
    linear_extrude(3) 
    polygon(points=[[0,0],[$width,0],[0,$height]], paths=[[0,1,2]]);
}
{
    rotate([90,0,-45])
    translate([$deltax,$deltay,$deltaz])
    linear_extrude(3) 
    polygon(points=[[0,0],[$width,0],[0,$height]], paths=[[0,1,2]]);
}
{
    rotate([90,0,135])
    translate([$deltax,$deltay,$deltaz])
    linear_extrude(3) 
    polygon(points=[[0,0],[$width,0],[0,$height]], paths=[[0,1,2]]);
}
{
    rotate([90,0,225])
    translate([$deltax,$deltay,$deltaz])
    linear_extrude(3) 
    polygon(points=[[0,0],[$width,0],[0,$height]], paths=[[0,1,2]]);
}
}