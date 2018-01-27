package main
import "fmt"
import "math"

const s string = "constant"

func main() {
    fmt.Println(s)
    const n = 50
    const d = 320 / n
    fmt.Println(d)
    fmt.Println(int64(d))
    fmt.Println(math.Sin(n))
}
