package main;
import "fmt";
func main() {

    var a[5] int;

    a[4] = 100;
    fmt.Println("get:", a[4]);

    fmt.Println("len:",5);
    
    var i int;
    var j int;
    var twoD int = 1;	
    for i = 0; i < 2; i++ {
        for j = 0; j < 3; j++ {
            twoD = twoD +  i + j;
        };
    };
    fmt.Println("2d: ", twoD);
}
