package android.example.robotsgonnarescue;

import android.graphics.Canvas;
import android.graphics.Paint;

import com.github.mikephil.charting.interfaces.datasets.IScatterDataSet;
import com.github.mikephil.charting.renderer.scatter.IShapeRenderer;
import com.github.mikephil.charting.utils.ViewPortHandler;

/**
 * Custom shape renderer that draws a single line.
 * Ben Pierre, Patrick Wenzel, Andrew Holman
 */
public class CustomScatterShapeRenderer implements IShapeRenderer
{

/**
 * Renders the shape of the scatter chart graph.
 * @param c is the Canvas that the graph is drawn on.
 * @param dataSet is the data set used to draw the graph.
 * @param viewPortHandler is the view used in the XML to display the canvas.
 * @param posX is the x position that is to be added to the graph.
 * @param posY is the y position that is to be added to the graph.
 * @param renderPaint is the paint object used to draw the objects onto the canvas.
 */
    @Override
    public void renderShape(Canvas c, IScatterDataSet dataSet, ViewPortHandler viewPortHandler,
                            float posX, float posY, Paint renderPaint) {

        final float shapeHalf = dataSet.getScatterShapeSize() / 2f;

        c.drawLine(
                posX - shapeHalf,
                posY - shapeHalf,
                posX + shapeHalf,
                posY + shapeHalf,
                renderPaint);
    }
}
