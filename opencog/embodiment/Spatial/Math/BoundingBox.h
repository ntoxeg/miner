#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <vector>
#include "Vector3.h"
#include "LineSegment.h"
#include "SquareFace.h"

namespace Spatial {

  class Entity;

  namespace Math {

    class BoundingBox {
    public:
      
	/**
	 * Corners
	 *          
	 *      1+------+2
	 *      /|     /|
	 *     / |    / |
	 *   6+------+7 |
	 *    | 0+---|--+3
	 *    | /    | /
	 *    |/     |/
	 *   5+------+4
	 */
      enum CORNER {
	FAR_LEFT_BOTTOM,   // 0
	FAR_LEFT_TOP,      // 1
	FAR_RIGHT_TOP,     // 2
	FAR_RIGHT_BOTTOM,  // 3
	NEAR_RIGHT_BOTTOM, // 4
	NEAR_LEFT_BOTTOM,  // 5
	NEAR_LEFT_TOP,     // 6
	NEAR_RIGHT_TOP     // 7
      };
      
      /**
       * Constructor
       * @param entity the entity involved by the bounding box
       */
      BoundingBox( Entity* entity );


      /**
       * Get the spatial points corresponding to the corners of the bounding box
       * @return a vector containing all the bounding box corners
       */
      const std::vector<Vector3>& getAllCorners( void ) const;

      /**
       * Get the position of one of the corners
       * @param cornerToGet Specific corner
       * @return the corner position
       */
      const Vector3& getCorner(CORNER cornerToGet) const;

      /**
       * Get all the bounding box edges
       * @return the edges
       */
      const std::vector<LineSegment>& getAllEdges( void ) const;

      /**
       * Check if a given point is inside the bounding box
       * @param point
       * @return true if the point is inside or false otherwise
       */
      bool isInside( const Vector3& point ) const;

      /**
       * Return the square faces of bounding box
       * @return all the faces
       */
      const std::vector<SquareFace>& getAllFaces( void );

      /**
       * Update the bounding box rebuilding the corners positions
       */
      void update( void );

      /**
       * Return the distance between a given point and this bb
       */
      double distanceTo( const Vector3& point ) const;

      bool operator==( const BoundingBox& bb ) const;

      BoundingBox& operator=( const BoundingBox& bb );
            
    private:
      void buildCorners( void );
      void buildFaces( void );
      void buildEdges( void );

      Entity* entity;
      std::vector<SquareFace> squareFaces;
      std::vector<LineSegment> edges;
      std::vector<Vector3> corners;

    }; // BoundingBox

  }; // Math
}; // Spatial

#endif // BOUNDINGBOX_H
