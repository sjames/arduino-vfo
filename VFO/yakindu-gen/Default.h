
#ifndef DEFAULT_H_
#define DEFAULT_H_


#include "../src/sc_types.h"
#include "../src/StatemachineInterface.h"

/*! \file Header of the state machine 'default'.
*/



/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_REGION_INITIALIZE 0
#define SCVI_MAIN_REGION_MAIN 0
#define SCVI_MAIN_REGION_MAIN_R1_MENUBAR 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR_CLK0_HIGHLIGHTED 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR_CLK0_SELECTED 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR_CLK0_SETMULTIPLIER 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR_CLK1_HIGHLIGHTED 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR_CLK1_SELECTED 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR_CLK1_SETMULTIPLIER 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR_CLK2_HIGHLIGHTED 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR_CLK2_SELECTED 0
#define SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR_CLK2_SETMULTIPLIER 0
#define SCVI_GENERATOR_INITIALIZE 1
#define SCVI_GENERATOR_RUNNING 1
#define SCVI_GENERATOR_RUNNING_CLK0_OFF 1
#define SCVI_GENERATOR_RUNNING_CLK0_ON 1
#define SCVI_GENERATOR_RUNNING_CLK1_OFF 2
#define SCVI_GENERATOR_RUNNING_CLK1_ON 2
#define SCVI_GENERATOR_RUNNING_CLK2_OFF 3
#define SCVI_GENERATOR_RUNNING_CLK2_ON 3

class Default : public StatemachineInterface
{
	public:
		Default();
		
		~Default();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			Default_last_state,
			main_region_initialize,
			main_region_main,
			main_region_main_r1_menubar,
			main_region_main_r1_freq0bar,
			main_region_main_r1_freq0bar_clk0_Highlighted,
			main_region_main_r1_freq0bar_clk0_Selected,
			main_region_main_r1_freq0bar_clk0_SetMultiplier,
			main_region_main_r1_freq1bar,
			main_region_main_r1_freq1bar_clk1_Highlighted,
			main_region_main_r1_freq1bar_clk1_Selected,
			main_region_main_r1_freq1bar_clk1_SetMultiplier,
			main_region_main_r1_freq2bar,
			main_region_main_r1_freq2bar_clk2_Highlighted,
			main_region_main_r1_freq2bar_clk2_Selected,
			main_region_main_r1_freq2bar_clk2_SetMultiplier,
			Generator_Initialize,
			Generator_Running,
			Generator_Running_CLK0_Off,
			Generator_Running_CLK0_On,
			Generator_Running_CLK1_Off,
			Generator_Running_CLK1_On,
			Generator_Running_CLK2_Off,
			Generator_Running_CLK2_On
		} DefaultStates;
		
		static const sc_integer numStates = 23;
		
		//! Inner class for default interface scope.
		class DefaultSCI
		{
			
			public:
				/*! Raises the in event 'eReady' that is defined in the default interface scope. */
				void raise_eReady();
				
				/*! Raises the in event 'eShortPress' that is defined in the default interface scope. */
				void raise_eShortPress();
				
				/*! Raises the in event 'eLongPress' that is defined in the default interface scope. */
				void raise_eLongPress();
				
				/*! Raises the in event 'eClockWiseTick' that is defined in the default interface scope. */
				void raise_eClockWiseTick(sc_integer value);
				
				/*! Raises the in event 'eCounterClockWiseTick' that is defined in the default interface scope. */
				void raise_eCounterClockWiseTick(sc_integer value);
				
				/*! Raises the in event 'eUpdateDisplay' that is defined in the default interface scope. */
				void raise_eUpdateDisplay();
				
				/*! Gets the value of the variable 'clock0Freq' that is defined in the default interface scope. */
				sc_integer get_clock0Freq() const;
				
				/*! Sets the value of the variable 'clock0Freq' that is defined in the default interface scope. */
				void set_clock0Freq(sc_integer value);
				
				/*! Gets the value of the variable 'clock1Freq' that is defined in the default interface scope. */
				sc_integer get_clock1Freq() const;
				
				/*! Sets the value of the variable 'clock1Freq' that is defined in the default interface scope. */
				void set_clock1Freq(sc_integer value);
				
				/*! Gets the value of the variable 'clock2Freq' that is defined in the default interface scope. */
				sc_integer get_clock2Freq() const;
				
				/*! Sets the value of the variable 'clock2Freq' that is defined in the default interface scope. */
				void set_clock2Freq(sc_integer value);
				
				/*! Gets the value of the variable 'clock0ReqFreq' that is defined in the default interface scope. */
				sc_integer get_clock0ReqFreq() const;
				
				/*! Sets the value of the variable 'clock0ReqFreq' that is defined in the default interface scope. */
				void set_clock0ReqFreq(sc_integer value);
				
				/*! Gets the value of the variable 'clock1ReqFreq' that is defined in the default interface scope. */
				sc_integer get_clock1ReqFreq() const;
				
				/*! Sets the value of the variable 'clock1ReqFreq' that is defined in the default interface scope. */
				void set_clock1ReqFreq(sc_integer value);
				
				/*! Gets the value of the variable 'clock2ReqFreq' that is defined in the default interface scope. */
				sc_integer get_clock2ReqFreq() const;
				
				/*! Sets the value of the variable 'clock2ReqFreq' that is defined in the default interface scope. */
				void set_clock2ReqFreq(sc_integer value);
				
				/*! Gets the value of the variable 'clock0Multiplier' that is defined in the default interface scope. */
				sc_integer get_clock0Multiplier() const;
				
				/*! Sets the value of the variable 'clock0Multiplier' that is defined in the default interface scope. */
				void set_clock0Multiplier(sc_integer value);
				
				/*! Gets the value of the variable 'clock1Multiplier' that is defined in the default interface scope. */
				sc_integer get_clock1Multiplier() const;
				
				/*! Sets the value of the variable 'clock1Multiplier' that is defined in the default interface scope. */
				void set_clock1Multiplier(sc_integer value);
				
				/*! Gets the value of the variable 'clock2Multiplier' that is defined in the default interface scope. */
				sc_integer get_clock2Multiplier() const;
				
				/*! Sets the value of the variable 'clock2Multiplier' that is defined in the default interface scope. */
				void set_clock2Multiplier(sc_integer value);
				
				
			private:
				friend class Default;
				sc_boolean eReady_raised;
				sc_boolean eShortPress_raised;
				sc_boolean eLongPress_raised;
				sc_boolean eClockWiseTick_raised;
				sc_integer eClockWiseTick_value;
				sc_boolean eCounterClockWiseTick_raised;
				sc_integer eCounterClockWiseTick_value;
				sc_boolean eUpdateDisplay_raised;
				sc_integer clock0Freq;
				sc_integer clock1Freq;
				sc_integer clock2Freq;
				sc_integer clock0ReqFreq;
				sc_integer clock1ReqFreq;
				sc_integer clock2ReqFreq;
				sc_integer clock0Multiplier;
				sc_integer clock1Multiplier;
				sc_integer clock2Multiplier;
		};
				//! Inner class for default interface scope operation callbacks.
				class DefaultSCI_OCB
				{
					public:
						virtual ~DefaultSCI_OCB() = 0;
						
						virtual void updateClock(sc_integer id) = 0;
						
						virtual void updateDisplay() = 0;
						
						virtual void enableClock(sc_integer id) = 0;
						
						virtual void disableClock(sc_integer id) = 0;
				};
				
				/*! Set the working instance of the operation callback interface 'DefaultSCI_OCB'. */
				void setDefaultSCI_OCB(DefaultSCI_OCB* operationCallback);
		
		/*! Returns an instance of the interface class 'DefaultSCI'. */
		DefaultSCI* getDefaultSCI();
		
		/*! Raises the in event 'eReady' that is defined in the default interface scope. */
		void raise_eReady();
		
		/*! Raises the in event 'eShortPress' that is defined in the default interface scope. */
		void raise_eShortPress();
		
		/*! Raises the in event 'eLongPress' that is defined in the default interface scope. */
		void raise_eLongPress();
		
		/*! Raises the in event 'eClockWiseTick' that is defined in the default interface scope. */
		void raise_eClockWiseTick(sc_integer value);
		
		/*! Raises the in event 'eCounterClockWiseTick' that is defined in the default interface scope. */
		void raise_eCounterClockWiseTick(sc_integer value);
		
		/*! Raises the in event 'eUpdateDisplay' that is defined in the default interface scope. */
		void raise_eUpdateDisplay();
		
		/*! Gets the value of the variable 'clock0Freq' that is defined in the default interface scope. */
		sc_integer get_clock0Freq() const;
		
		/*! Sets the value of the variable 'clock0Freq' that is defined in the default interface scope. */
		void set_clock0Freq(sc_integer value);
		
		/*! Gets the value of the variable 'clock1Freq' that is defined in the default interface scope. */
		sc_integer get_clock1Freq() const;
		
		/*! Sets the value of the variable 'clock1Freq' that is defined in the default interface scope. */
		void set_clock1Freq(sc_integer value);
		
		/*! Gets the value of the variable 'clock2Freq' that is defined in the default interface scope. */
		sc_integer get_clock2Freq() const;
		
		/*! Sets the value of the variable 'clock2Freq' that is defined in the default interface scope. */
		void set_clock2Freq(sc_integer value);
		
		/*! Gets the value of the variable 'clock0ReqFreq' that is defined in the default interface scope. */
		sc_integer get_clock0ReqFreq() const;
		
		/*! Sets the value of the variable 'clock0ReqFreq' that is defined in the default interface scope. */
		void set_clock0ReqFreq(sc_integer value);
		
		/*! Gets the value of the variable 'clock1ReqFreq' that is defined in the default interface scope. */
		sc_integer get_clock1ReqFreq() const;
		
		/*! Sets the value of the variable 'clock1ReqFreq' that is defined in the default interface scope. */
		void set_clock1ReqFreq(sc_integer value);
		
		/*! Gets the value of the variable 'clock2ReqFreq' that is defined in the default interface scope. */
		sc_integer get_clock2ReqFreq() const;
		
		/*! Sets the value of the variable 'clock2ReqFreq' that is defined in the default interface scope. */
		void set_clock2ReqFreq(sc_integer value);
		
		/*! Gets the value of the variable 'clock0Multiplier' that is defined in the default interface scope. */
		sc_integer get_clock0Multiplier() const;
		
		/*! Sets the value of the variable 'clock0Multiplier' that is defined in the default interface scope. */
		void set_clock0Multiplier(sc_integer value);
		
		/*! Gets the value of the variable 'clock1Multiplier' that is defined in the default interface scope. */
		sc_integer get_clock1Multiplier() const;
		
		/*! Sets the value of the variable 'clock1Multiplier' that is defined in the default interface scope. */
		void set_clock1Multiplier(sc_integer value);
		
		/*! Gets the value of the variable 'clock2Multiplier' that is defined in the default interface scope. */
		sc_integer get_clock2Multiplier() const;
		
		/*! Sets the value of the variable 'clock2Multiplier' that is defined in the default interface scope. */
		void set_clock2Multiplier(sc_integer value);
		
		
		/*
		 * Functions inherited from StatemachineInterface
		 */
		virtual void init();
		
		virtual void enter();
		
		virtual void exit();
		
		virtual void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		virtual sc_boolean isActive() const;
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		virtual sc_boolean isFinal() const;
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(DefaultStates state) const;
		
	protected:
	private:
		Default(const Default &rhs);
		Default& operator=(const Default&);
		
		//! Inner class for internal interface scope.
		class InternalSCI
		{
			
			public:
				/*! Raises the in event 'eGeneratorInitialized' that is defined in the internal scope. */
				void raise_eGeneratorInitialized();
				
				/*! Checks if the out event 'eGeneratorInitialized' that is defined in the internal scope has been raised. */
				sc_boolean isRaised_eGeneratorInitialized() const;
				
				/*! Raises the in event 'eClock0Toggle' that is defined in the internal scope. */
				void raise_eClock0Toggle();
				
				/*! Checks if the out event 'eClock0Toggle' that is defined in the internal scope has been raised. */
				sc_boolean isRaised_eClock0Toggle() const;
				
				/*! Raises the in event 'eClock1Toggle' that is defined in the internal scope. */
				void raise_eClock1Toggle();
				
				/*! Checks if the out event 'eClock1Toggle' that is defined in the internal scope has been raised. */
				sc_boolean isRaised_eClock1Toggle() const;
				
				/*! Raises the in event 'eClock2Toggle' that is defined in the internal scope. */
				void raise_eClock2Toggle();
				
				/*! Checks if the out event 'eClock2Toggle' that is defined in the internal scope has been raised. */
				sc_boolean isRaised_eClock2Toggle() const;
				
				/*! Raises the in event 'eClockUpdate' that is defined in the internal scope. */
				void raise_eClockUpdate();
				
				/*! Checks if the out event 'eClockUpdate' that is defined in the internal scope has been raised. */
				sc_boolean isRaised_eClockUpdate() const;
				
				
			private:
				friend class Default;
				sc_boolean eGeneratorInitialized_raised;
				sc_boolean eClock0Toggle_raised;
				sc_boolean eClock1Toggle_raised;
				sc_boolean eClock2Toggle_raised;
				sc_boolean eClockUpdate_raised;
		};
		
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_ushort maxOrthogonalStates = 4;
		
		
		DefaultStates stateConfVector[maxOrthogonalStates];
		
		sc_ushort stateConfVectorPosition;
		
		DefaultSCI iface;
		DefaultSCI_OCB* iface_OCB;
		InternalSCI ifaceInternalSCI;
		
		// prototypes of all internal functions
		
		void enact_main_region_initialize();
		void enact_Generator_Initialize();
		void enact_Generator_Running_CLK0_Off();
		void enact_Generator_Running_CLK0_On();
		void enact_Generator_Running_CLK1_Off();
		void enact_Generator_Running_CLK1_On();
		void enact_Generator_Running_CLK2_Off();
		void enact_Generator_Running_CLK2_On();
		void enseq_main_region_initialize_default();
		void enseq_main_region_main_default();
		void enseq_main_region_main_r1_menubar_default();
		void enseq_main_region_main_r1_freq0bar_default();
		void enseq_main_region_main_r1_freq0bar_clk0_Highlighted_default();
		void enseq_main_region_main_r1_freq0bar_clk0_Selected_default();
		void enseq_main_region_main_r1_freq0bar_clk0_SetMultiplier_default();
		void enseq_main_region_main_r1_freq1bar_default();
		void enseq_main_region_main_r1_freq1bar_clk1_Highlighted_default();
		void enseq_main_region_main_r1_freq1bar_clk1_Selected_default();
		void enseq_main_region_main_r1_freq1bar_clk1_SetMultiplier_default();
		void enseq_main_region_main_r1_freq2bar_default();
		void enseq_main_region_main_r1_freq2bar_clk2_Highlighted_default();
		void enseq_main_region_main_r1_freq2bar_clk2_Selected_default();
		void enseq_main_region_main_r1_freq2bar_clk2_SetMultiplier_default();
		void enseq_Generator_Initialize_default();
		void enseq_Generator_Running_default();
		void enseq_Generator_Running_CLK0_Off_default();
		void enseq_Generator_Running_CLK0_On_default();
		void enseq_Generator_Running_CLK1_Off_default();
		void enseq_Generator_Running_CLK1_On_default();
		void enseq_Generator_Running_CLK2_Off_default();
		void enseq_Generator_Running_CLK2_On_default();
		void enseq_main_region_default();
		void enseq_main_region_main_r1_default();
		void enseq_main_region_main_r1_freq0bar_clk0_default();
		void enseq_main_region_main_r1_freq1bar_clk1_default();
		void enseq_main_region_main_r1_freq2bar_clk2_default();
		void enseq_Generator_default();
		void enseq_Generator_Running_CLK0_default();
		void enseq_Generator_Running_CLK1_default();
		void enseq_Generator_Running_CLK2_default();
		void exseq_main_region_initialize();
		void exseq_main_region_main_r1_menubar();
		void exseq_main_region_main_r1_freq0bar();
		void exseq_main_region_main_r1_freq0bar_clk0_Highlighted();
		void exseq_main_region_main_r1_freq0bar_clk0_Selected();
		void exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
		void exseq_main_region_main_r1_freq1bar();
		void exseq_main_region_main_r1_freq1bar_clk1_Highlighted();
		void exseq_main_region_main_r1_freq1bar_clk1_Selected();
		void exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
		void exseq_main_region_main_r1_freq2bar();
		void exseq_main_region_main_r1_freq2bar_clk2_Highlighted();
		void exseq_main_region_main_r1_freq2bar_clk2_Selected();
		void exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
		void exseq_Generator_Initialize();
		void exseq_Generator_Running_CLK0_Off();
		void exseq_Generator_Running_CLK0_On();
		void exseq_Generator_Running_CLK1_Off();
		void exseq_Generator_Running_CLK1_On();
		void exseq_Generator_Running_CLK2_Off();
		void exseq_Generator_Running_CLK2_On();
		void exseq_main_region();
		void exseq_main_region_main_r1();
		void exseq_main_region_main_r1_freq0bar_clk0();
		void exseq_main_region_main_r1_freq1bar_clk1();
		void exseq_main_region_main_r1_freq2bar_clk2();
		void exseq_Generator();
		void exseq_Generator_Running_CLK0();
		void exseq_Generator_Running_CLK1();
		void exseq_Generator_Running_CLK2();
		void react_main_region__entry_Default();
		void react_main_region_main_r1_freq0bar_clk0__entry_Default();
		void react_main_region_main_r1_freq1bar_clk1__entry_Default();
		void react_main_region_main_r1_freq2bar_clk2__entry_Default();
		void react_main_region_main_r1__entry_Default();
		void react_Generator__entry_Default();
		void react_Generator_Running_CLK0__entry_Default();
		void react_Generator_Running_CLK1__entry_Default();
		void react_Generator_Running_CLK2__entry_Default();
		sc_boolean react(const sc_boolean try_transition);
		sc_boolean main_region_initialize_react(const sc_boolean try_transition);
		sc_boolean main_region_main_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_menubar_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq0bar_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq0bar_clk0_Highlighted_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq0bar_clk0_Selected_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq0bar_clk0_SetMultiplier_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq1bar_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq1bar_clk1_Highlighted_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq1bar_clk1_Selected_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq1bar_clk1_SetMultiplier_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq2bar_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq2bar_clk2_Highlighted_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq2bar_clk2_Selected_react(const sc_boolean try_transition);
		sc_boolean main_region_main_r1_freq2bar_clk2_SetMultiplier_react(const sc_boolean try_transition);
		sc_boolean Generator_Initialize_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_CLK0_Off_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_CLK0_On_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_CLK1_Off_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_CLK1_On_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_CLK2_Off_react(const sc_boolean try_transition);
		sc_boolean Generator_Running_CLK2_On_react(const sc_boolean try_transition);
		void clearInEvents();
		void clearOutEvents();
		
};

inline Default::DefaultSCI_OCB::~DefaultSCI_OCB() {}



#endif /* DEFAULT_H_ */
