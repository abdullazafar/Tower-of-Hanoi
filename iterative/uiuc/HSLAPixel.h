#pragma once

namespace uiuc
{
    class HSLAPixel
    {
        public:
        
        double h; // Hue of the pixel in degrees [0, 360]
        double s; // Saturation of the pixel [0, 1]
        double l; // Luminance of the pixe [0, 1]
        double a; // Alpha of the pixel [0, 1]

        // A default pixel is compeleely opaque (not-transparent) and white
        // Opaque implies that the alpha component of the pixel is 1.0
        // Lower alpha values are semi-transparent 
        HSLAPixel();


        // Constructs an opaque HSLAPixel with te given hue, saturation,
        // and luminance values
        HSLAPixel(double hue, double saturation, double luminance);

        // Constructs an HSLAPixel with the given hue, saturation, 
        // luminance and alpha values
        HSLAPixel(double hue, double saturation, double luminance, double alpha);
    
        static HSLAPixel BLUE;
        static HSLAPixel ORANGE;
        static HSLAPixel YELLOW;
        static HSLAPixel PURPLE;
    };
}