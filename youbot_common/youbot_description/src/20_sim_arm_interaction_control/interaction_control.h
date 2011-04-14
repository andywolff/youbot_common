/**********************************************************
 * This file is generated by 20-sim C++ Code Generator
 *
 *  file:  interaction_control.h
 *  subm:  interaction_control
 *  model: ControlYoubotArmInteraction_v2
 *  expmt: ControlYoubotArmInteraction_v2
 *  date:  April 12, 2011
 *  time:  4:52:06 pm
 *  user:  Campuslicentie
 *  from:  Universiteit Twente
 *  build: 4.1.2.2
 *
 **********************************************************/

/* This file describes the model functions
   that are supplied for computation.

   The model itself is the interaction_control.cpp file
*/

/* 20-sim include files */
#include "common/xxfuncs.h"
#include "common/xxmatrix.h"
#include "common/xxmodel.h"
#include "common/xxinteg.h"
#include "string"

#ifndef interaction_control_H
#define interaction_control_H


class interaction_control: public virtual Submodel20sim
{
	public:
		enum stateflags_interaction_control {initialrun, mainrun, finished};

		/**
		 * interaction_control constructor
		 */
		interaction_control(void);

		/**
		 * interaction_control destructor
		 */
		virtual ~interaction_control(void);

		/**
		 * interaction_control initialization
		 * @param u	This is the array with all input signals for this submodel
		 * @param y	This is the array with all output signals from this submodel
		 */
		void Initialize (XXDouble *u, XXDouble *y, XXDouble t);

		/**
		 * interaction_control Calculate
		 * @param u	This is the array with all input signals for this submodel
		 * @param y	This is the array with all output signals from this submodel
		 */
		void Calculate (XXDouble *u, XXDouble *y /*, XXDouble t*/ );

		/**
		 * interaction_control Terminate
		 * @param u	This is the array with all input signals for this submodel
		 * @param y	This is the array with all output signals from this submodel
		 */
		void Terminate (XXDouble *u, XXDouble *y /*, XXDouble t*/ );

		XXDouble GetTime(void)
		{
			return m_time;
		}

		stateflags_interaction_control state;

	protected:
		/**
		 * CalculateDynamic()
		 * This function calculates the dynamic equations of the model.
		 * These equations are called from the integration method
		 * to calculate the new model rates (that are then integrated).
		 */
		void CalculateDynamic (void);

	private:
		/* internal submodel computation methods */

		/**
		 * CalculateInitial()
		 * This function calculates the initial equations of the model.
		 * These equations are calculated before anything else
		 */
		void CalculateInitial (void);

		/**
		 * CalculateStatic()
		 * This function calculates the static equations of the model.
		 * These equations are only dependent from parameters and constants
		 */
		void CalculateStatic (void);

		/**
		 * CalculateInput()
		 * This function calculates the input equations of the model.
		 * These equations are dynamic equations that must not change
		 * in calls from the integration method (like random and delay).
		 */
		void CalculateInput (void);

		/**
		 * CalculateOutput()
		 * This function calculates the output equations of the model.
		 * These equations are not needed for calculation of the rates
		 * and are kept separate to make the dynamic set of equations smaller.
		 * These dynamic equations are called often more than one time for each
		 * integration step that is taken. This makes model computation much faster.
		 */
		void CalculateOutput (void);

		/**
		 * CalculateFinal()
		 * This function calculates the final equations of the model.
		 * These equations are calculated after all the calculations
		 * are performed
		 */
		void CalculateFinal (void);

		/**
		 * CopyInputsToVariables
		 * This private function copies the input variables from the input vector
		 * @param u	This is the array with all input signals for this submodel
		 */
		void CopyInputsToVariables (XXDouble *u);

		/**
		 * CopyVariablesToOutputs
		 * This private function copies the output variables to the output vector
		 * @param y	This is the array with all output signals from this submodel
		 */
		void CopyVariablesToOutputs (XXDouble *y);
	
		void initVarNames(void);

		Euler myintegmethod;	///< pointer to the integration method for this submodel
	

};

#endif	// interaction_control_H

