import java.awt.Color
import java.io.File
import javax.imageio.ImageIO

fun compress (list: List<String>): List<String> {
    val result: MutableList<String> = mutableListOf()
    var count: Int = 0
    var cur = list[0]

    for (index in list.indices) {
        if (cur == list[index]) {
            count++
        }
        else {
            result.add("[$count, ($cur)]")
            cur = list[index]
            count = 1
        }
    }
    result.add("[$count, ($cur)]")

    return result
}

fun get_norm_rgb(c: Color): String = "[${c.red} ${c.green} ${c.blue}]"

fun main(arg: Array<String>) {
    val image = ImageIO.read(File("./1.bmp"))
    val line: MutableList<String> = mutableListOf()

    for (y in 0..image.height.dec()) {
        for (x in 0..image.width.dec()) {
            line.add(get_norm_rgb(Color(image.getRGB(x, y))))
        }
        println(compress(line.toList()))
        line.clear()
    }
}