import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Guii extends JFrame {

    private JPanel pan;
    private JLabel shapeLabel, input1Label, input2Label, areaLabel, perimeterLabel;
    private JLabel areaResult, perimeterResult;
    private JComboBox<String> shapeBox;
    private JButton displayButton, resetButton, exitButton;
    private JTextField input1Field, input2Field;

    public Guii() {
        setTitle("Geometric Object Area & Perimeter Calculator");
        setSize(450, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // Initialize components
        String[] shapes = {"Rectangle", "Square", "Circle"};
        shapeBox = new JComboBox<>(shapes);
        shapeBox.addActionListener(new ShapeSelectionHandler());

        shapeLabel = new JLabel("Select your Geometric Object:");
        input1Label = new JLabel("Enter length:");
        input2Label = new JLabel("Enter width:");
        areaLabel = new JLabel("Area:");
        perimeterLabel = new JLabel("Perimeter:");
        areaResult = new JLabel();
        perimeterResult = new JLabel();
        input1Field = new JTextField(5);
        input2Field = new JTextField(5);

        displayButton = new JButton("Display");
        displayButton.addActionListener(new CalculateHandler());

        resetButton = new JButton("Reset");
        resetButton.addActionListener(e -> resetInputs());

        exitButton = new JButton("OFF");
        exitButton.setForeground(Color.RED);
        exitButton.addActionListener(e -> dispose());

        // Panel layout
        pan = new JPanel(new GridLayout(7, 2));
        pan.add(shapeLabel);       pan.add(shapeBox);
        pan.add(input1Label);      pan.add(input1Field);
        pan.add(input2Label);      pan.add(input2Field);
        pan.add(displayButton);    pan.add(resetButton);
        pan.add(areaLabel);        pan.add(areaResult);
        pan.add(perimeterLabel);   pan.add(perimeterResult);
        pan.add(exitButton);

        add(pan);
        setVisible(true);
    }

    private void resetInputs() {
        input1Field.setText("");
        input2Field.setText("");
        areaResult.setText("");
        perimeterResult.setText("");
    }

    private void displayResults(double area, double perimeter) {
        areaResult.setText(String.format("%.2f", area));
        perimeterResult.setText(String.format("%.2f", perimeter));
    }

    // Inner class: Handles shape change
    class ShapeSelectionHandler implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            int selected = shapeBox.getSelectedIndex();
            switch (selected) {
                case 0: // Rectangle
                    input1Label.setText("Enter length:");
                    input2Label.setVisible(true);
                    input2Field.setVisible(true);
                    break;
                case 1: // Square
                    input1Label.setText("Enter a side:");
                    input2Label.setVisible(false);
                    input2Field.setVisible(false);
                    break;
                case 2: // Circle
                    input1Label.setText("Enter a Radius:");
                    input2Label.setVisible(false);
                    input2Field.setVisible(false);
                    break;
            }
        }
    }

    // Inner class: Handles calculation
    class CalculateHandler implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            try {
                int selected = shapeBox.getSelectedIndex();
                switch (selected) {
                    case 0: // Rectangle
                        double len = Double.parseDouble(input1Field.getText());
                        double wid = Double.parseDouble(input2Field.getText());
                        if (len > 0 && wid > 0) {
                            Rectangle rect = new Rectangle(len, wid);
                            displayResults(rect.getArea(), rect.getperimeter());
                        } else throw new Exception();
                        break;

                    case 1: // Square
                        double side = Double.parseDouble(input1Field.getText());
                        if (side > 0) {
                            Square sq = new Square(side);
                            displayResults(sq.getArea(), sq.getperimeter());
                        } else throw new Exception();
                        break;

                    case 2: // Circle
                        double radius = Double.parseDouble(input1Field.getText());
                        if (radius > 0) {
                            Circle cir = new Circle(radius);
                            displayResults(cir.getArea(), cir.getperimeter());
                        } else throw new Exception();
                        break;
                }
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "Enter valid positive numbers only.");
            }
        }
    }
}
