import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.List;

public class Main {

    private static String get_color_norm(Color c) {
        return "[" + String.valueOf(255-c.getRed()) + ", " + String.valueOf(255-c.getGreen()) + ", " + String.valueOf(255-c.getBlue()) + "]";
    }

    private static List<String> compress(int w, String[] line) {
        List<String> res_line = new ArrayList<>();
        int counter = 1;
        String curr = line[0];

        for (int i = 1; i < w; i++) {
            if (Objects.equals(line[i], curr)) {
                counter++;
            } else {
                res_line.add("(" + String.valueOf(counter) + ", " + curr + ")");
                curr = line[i];
                counter = 1;
            }
        }
        res_line.add("(" + String.valueOf(counter) + ", " + curr + ")");

        return res_line;
    }

    public static void main(String[] args) throws IOException {

        BufferedImage img = ImageIO.read(new File("../1.bmp"));
        int width = img.getWidth();
        int height = img.getHeight();
        String[][] mat = new String[width][height];

        for(int x = 0; x < width; x++) {
            for(int y = 0; y < height; y++) {
                mat[x][y] = get_color_norm(new Color(img.getRGB(x, y), true));
            }
        }

        FileWriter fileWriter = new FileWriter("out.rle");
        BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

        for(int x = 0; x < width; x++) {
            bufferedWriter.write(compress(height, mat[x]).toString() + "\n");
            System.out.println(compress(height, mat[x]).toString());
        }

        bufferedWriter.close();
    }
}
