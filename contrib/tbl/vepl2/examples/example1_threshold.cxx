//:
// \file
//  This example program shows a typical use of the vepl2_threshold function on
//  a ubyte image.  The input image (argv[1]) must be ubyte, and in that
//  case is thresholded (threshold value argv[3], default 127) to argv[2]
//  which is always a PGM file image.
//  The input and output images are directly passed to the filter.
//
// \author Peter Vanroose, K.U.Leuven, ESAT/PSI
// \date   7 October 2002, from vepl/examples
//
#include <vil/vil_load.h>
#include <vil/vil_save.h>
#include <vepl2/vepl2_threshold.h>
#include <vcl_iostream.h>
#include <vcl_cstdlib.h> // for atoi()
#include <vxl_config.h> // for vxl_byte

int
main(int argc, char** argv) {
  if (argc < 3) { vcl_cerr << "Syntax: example1_threshold file_in file_out [threshold]\n"; return 1; }

  // The input image:
  vil_image_resource_sptr in = vil_load_image_resource(argv[1]);
  if (!in) return 2;

  // The threshold value:
  vxl_byte threshold = (argc < 4) ? 127 : vcl_atoi(argv[3]);

  // The filter:
  vil_image_resource_sptr out = vepl2_threshold(in,threshold,0);
  // without 4th argument, only set below threshold to 0

  if (vil_save_image_resource(out, argv[2], "pnm"))
    vcl_cout << "Written thresholded image of type PNM to " << argv[2] << '\n';
  else
    vcl_cout << "Could not write thresholded image as PNM to "<< argv[2]<<'\n';
  return 0;
}
