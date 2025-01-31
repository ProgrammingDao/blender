/* SPDX-License-Identifier: GPL-2.0-or-later
 * Copyright 2010 Blender Foundation. All rights reserved. */

#pragma once

/** \file
 * \ingroup DNA
 */

#include "DNA_ID.h"
#include "DNA_listBase.h"

/* Notice that we need to have this file although no struct defines.
 * Edge flags and usage flags are used by with scene/object/gpencil modifier bits, and those values
 * needs to stay consistent throughout. */

/* These flags are used for 1 time calculation, not stroke selection afterwards. */
typedef enum eLineartMainFlags {
  LRT_INTERSECTION_AS_CONTOUR = (1 << 0),
  LRT_EVERYTHING_AS_CONTOUR = (1 << 1),
  LRT_ALLOW_DUPLI_OBJECTS = (1 << 2),
  LRT_ALLOW_OVERLAPPING_EDGES = (1 << 3),
  LRT_ALLOW_CLIPPING_BOUNDARIES = (1 << 4),
  /* LRT_REMOVE_DOUBLES = (1 << 5), Deprecated */
  LRT_LOOSE_AS_CONTOUR = (1 << 6),
  LRT_GPENCIL_INVERT_SOURCE_VGROUP = (1 << 7),
  LRT_GPENCIL_MATCH_OUTPUT_VGROUP = (1 << 8),
  LRT_FILTER_FACE_MARK = (1 << 9),
  LRT_FILTER_FACE_MARK_INVERT = (1 << 10),
  LRT_FILTER_FACE_MARK_BOUNDARIES = (1 << 11),
  LRT_CHAIN_LOOSE_EDGES = (1 << 12),
  LRT_CHAIN_GEOMETRY_SPACE = (1 << 13),
  LRT_ALLOW_OVERLAP_EDGE_TYPES = (1 << 14),
  LRT_USE_CREASE_ON_SMOOTH_SURFACES = (1 << 15),
  LRT_USE_CREASE_ON_SHARP_EDGES = (1 << 16),
  LRT_USE_CUSTOM_CAMERA = (1 << 17),
  LRT_FILTER_FACE_MARK_KEEP_CONTOUR = (1 << 18),
  LRT_USE_BACK_FACE_CULLING = (1 << 19),
  LRT_USE_IMAGE_BOUNDARY_TRIMMING = (1 << 20),
  LRT_CHAIN_PRESERVE_DETAILS = (1 << 22),
} eLineartMainFlags;

typedef enum eLineartEdgeFlag {
  LRT_EDGE_FLAG_EDGE_MARK = (1 << 0),
  LRT_EDGE_FLAG_CONTOUR = (1 << 1),
  LRT_EDGE_FLAG_CREASE = (1 << 2),
  LRT_EDGE_FLAG_MATERIAL = (1 << 3),
  LRT_EDGE_FLAG_INTERSECTION = (1 << 4),
  LRT_EDGE_FLAG_LOOSE = (1 << 5),
  /* LRT_EDGE_FLAG_FOR_FUTURE = (1 << 7), */
  /* Limited to 8 bits for edge type flag, don't add anymore because `BMEdge->head.eflag` only has
   * 8 bits. So unless we changed this into a non-single-bit flag thing, we keep it this way. */
  /** Also used as discarded line mark. */
  LRT_EDGE_FLAG_CHAIN_PICKED = (1 << 8),
  LRT_EDGE_FLAG_CLIPPED = (1 << 9),
  /** Limited to 16 bits for the entire thing. */

  /** For object loading code to use only. */
  LRT_EDGE_FLAG_INHIBIT = (1 << 14),
  /** For discarding duplicated edge types in culling stage. */
  LRT_EDGE_FLAG_NEXT_IS_DUPLICATION = (1 << 15),
} eLineartEdgeFlag;

#define LRT_EDGE_FLAG_ALL_TYPE 0x3f
