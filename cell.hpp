/*
 * cell.hpp
 *
 *  Created on: Apr 15, 2018
 *      Author: snytav
 */

#ifndef CELL_HPP_
#define CELL_HPP_


class Cell
{
public:

  int3 cnum;                              //mesh node number for this cell: lower left corner
  double tau;                             //timestep
  double3 hstep;                          //mesh step
  double3 xmin;                           //coordinate of the lower left corner of the cell
  double3 xmax;                           //domain size

  ParticleTarget *tgt;                    //special structure to gather particles flying out of simulation domain

  double beam_boundary;                   //initial boundary of the beam
  double beam_boundary_counter;           //number of beam particles that crossed the boundary

  int3 mesh;                              //number of mesh nodes
  CellDouble *Jx, *Ex, *Hx,*Jy, *Ey, *Hy,*Jz, *Ez, *Hz,*Rho; //local arrays of mesh values for this cell
                                          //including two mesh layers from each side for form-factor evaluation:
                                          //  node numbering      0          1    2    3     4   for form-factor
                                          //                      |extra-left|left|this|right|extra-right|


  int jmp;                                //total number of particles (legacy, for comparing with Fortran)

  double *d_ctrlParticles;                //imported Fortran particles

  int flag_wrong_current_cell;
  double *d_wrong_current_particle_attributes; //array of particle attributes for GPU
  double *h_wrong_current_particle_attributes; //and its copy on host

  double *doubParticleArray;
  int number_of_particles;
  int busyParticleArray;

  int arrival[3][3][3],departure[3][3][3];
  int departureListLength;
  Particle departureList[3][3][3][PARTICLES_FLYING_ONE_DIRECTION];
  double *doubArrivalArray;


};







#endif /* CELL_HPP_ */
