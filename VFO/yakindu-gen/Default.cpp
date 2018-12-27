
#include "Default.h"
#include <string.h>
#include <Wire.h>

/*! \file Implementation of the state machine 'default'
*/



Default::Default():
	stateConfVectorPosition(0),
	iface(),
	iface_OCB(null),
	ifaceInternalSCI()
{
}

Default::~Default()
{
}


void Default::init()
{
	for (sc_ushort i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = Default_last_state;
	
	stateConfVectorPosition = 0;

	clearInEvents();
	clearOutEvents();
	
	/* Default init sequence for statechart default */
	iface.clock0Freq = 0;
	iface.clock1Freq = 0;
	iface.clock2Freq = 0;
	iface.clock0ReqFreq = 70000000;
	iface.clock1ReqFreq = 140000000;
	iface.clock2ReqFreq = 35000000;
	iface.clock0Multiplier = 1;
	iface.clock1Multiplier = 1;
	iface.clock2Multiplier = 1;
}

void Default::enter()
{
	/* Default enter sequence for statechart default */
	enseq_main_region_default();
	enseq_Generator_default();
}

void Default::exit()
{
	/* Default exit sequence for statechart default */
	exseq_main_region();
	exseq_Generator();
}

sc_boolean Default::isActive() const
{
	return stateConfVector[0] != Default_last_state||stateConfVector[1] != Default_last_state||stateConfVector[2] != Default_last_state||stateConfVector[3] != Default_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Default::isFinal() const
{
   return false;}

void Default::runCycle()
{
	
	clearOutEvents();
	for (stateConfVectorPosition = 0;
		stateConfVectorPosition < maxOrthogonalStates;
		stateConfVectorPosition++)
		{
			
		switch (stateConfVector[stateConfVectorPosition])
		{
		case main_region_initialize :
		{
			main_region_initialize_react(true);
			break;
		}
		case main_region_main_r1_menubar :
		{
			main_region_main_r1_menubar_react(true);
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Highlighted :
		{
			main_region_main_r1_freq0bar_clk0_Highlighted_react(true);
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Selected :
		{
			main_region_main_r1_freq0bar_clk0_Selected_react(true);
			break;
		}
		case main_region_main_r1_freq0bar_clk0_SetMultiplier :
		{
			main_region_main_r1_freq0bar_clk0_SetMultiplier_react(true);
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Highlighted :
		{
			main_region_main_r1_freq1bar_clk1_Highlighted_react(true);
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Selected :
		{
			main_region_main_r1_freq1bar_clk1_Selected_react(true);
			break;
		}
		case main_region_main_r1_freq1bar_clk1_SetMultiplier :
		{
			main_region_main_r1_freq1bar_clk1_SetMultiplier_react(true);
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Highlighted :
		{
			main_region_main_r1_freq2bar_clk2_Highlighted_react(true);
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Selected :
		{
			main_region_main_r1_freq2bar_clk2_Selected_react(true);
			break;
		}
		case main_region_main_r1_freq2bar_clk2_SetMultiplier :
		{
			main_region_main_r1_freq2bar_clk2_SetMultiplier_react(true);
			break;
		}
		case Generator_Initialize :
		{
			Generator_Initialize_react(true);
			break;
		}
		case Generator_Running_CLK0_Off :
		{
			Generator_Running_CLK0_Off_react(true);
			break;
		}
		case Generator_Running_CLK0_On :
		{
			Generator_Running_CLK0_On_react(true);
			break;
		}
		case Generator_Running_CLK1_Off :
		{
			Generator_Running_CLK1_Off_react(true);
			break;
		}
		case Generator_Running_CLK1_On :
		{
			Generator_Running_CLK1_On_react(true);
			break;
		}
		case Generator_Running_CLK2_Off :
		{
			Generator_Running_CLK2_Off_react(true);
			break;
		}
		case Generator_Running_CLK2_On :
		{
			Generator_Running_CLK2_On_react(true);
			break;
		}
		default:
			break;
		}
	}
	clearInEvents();
}

void Default::clearInEvents()
{
	iface.eReady_raised = false;
	iface.eShortPress_raised = false;
	iface.eLongPress_raised = false;
	iface.eClockWiseTick_raised = false;
	iface.eCounterClockWiseTick_raised = false;
	iface.eUpdateDisplay_raised = false;
	ifaceInternalSCI.eGeneratorInitialized_raised = false; 
	ifaceInternalSCI.eClock0Toggle_raised = false; 
	ifaceInternalSCI.eClock1Toggle_raised = false; 
	ifaceInternalSCI.eClock2Toggle_raised = false; 
	ifaceInternalSCI.eClockUpdate_raised = false; 
}

void Default::clearOutEvents()
{
}


sc_boolean Default::isStateActive(DefaultStates state) const
{
	switch (state)
	{
		case main_region_initialize : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_INITIALIZE] == main_region_initialize
			);
		case main_region_main : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN] >= main_region_main
				&& stateConfVector[SCVI_MAIN_REGION_MAIN] <= main_region_main_r1_freq2bar_clk2_SetMultiplier);
		case main_region_main_r1_menubar : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_MENUBAR] == main_region_main_r1_menubar
			);
		case main_region_main_r1_freq0bar : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR] >= main_region_main_r1_freq0bar
				&& stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR] <= main_region_main_r1_freq0bar_clk0_SetMultiplier);
		case main_region_main_r1_freq0bar_clk0_Highlighted : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR_CLK0_HIGHLIGHTED] == main_region_main_r1_freq0bar_clk0_Highlighted
			);
		case main_region_main_r1_freq0bar_clk0_Selected : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR_CLK0_SELECTED] == main_region_main_r1_freq0bar_clk0_Selected
			);
		case main_region_main_r1_freq0bar_clk0_SetMultiplier : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ0BAR_CLK0_SETMULTIPLIER] == main_region_main_r1_freq0bar_clk0_SetMultiplier
			);
		case main_region_main_r1_freq1bar : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR] >= main_region_main_r1_freq1bar
				&& stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR] <= main_region_main_r1_freq1bar_clk1_SetMultiplier);
		case main_region_main_r1_freq1bar_clk1_Highlighted : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR_CLK1_HIGHLIGHTED] == main_region_main_r1_freq1bar_clk1_Highlighted
			);
		case main_region_main_r1_freq1bar_clk1_Selected : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR_CLK1_SELECTED] == main_region_main_r1_freq1bar_clk1_Selected
			);
		case main_region_main_r1_freq1bar_clk1_SetMultiplier : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ1BAR_CLK1_SETMULTIPLIER] == main_region_main_r1_freq1bar_clk1_SetMultiplier
			);
		case main_region_main_r1_freq2bar : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR] >= main_region_main_r1_freq2bar
				&& stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR] <= main_region_main_r1_freq2bar_clk2_SetMultiplier);
		case main_region_main_r1_freq2bar_clk2_Highlighted : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR_CLK2_HIGHLIGHTED] == main_region_main_r1_freq2bar_clk2_Highlighted
			);
		case main_region_main_r1_freq2bar_clk2_Selected : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR_CLK2_SELECTED] == main_region_main_r1_freq2bar_clk2_Selected
			);
		case main_region_main_r1_freq2bar_clk2_SetMultiplier : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_MAIN_R1_FREQ2BAR_CLK2_SETMULTIPLIER] == main_region_main_r1_freq2bar_clk2_SetMultiplier
			);
		case Generator_Initialize : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_INITIALIZE] == Generator_Initialize
			);
		case Generator_Running : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING] >= Generator_Running
				&& stateConfVector[SCVI_GENERATOR_RUNNING] <= Generator_Running_CLK2_On);
		case Generator_Running_CLK0_Off : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING_CLK0_OFF] == Generator_Running_CLK0_Off
			);
		case Generator_Running_CLK0_On : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING_CLK0_ON] == Generator_Running_CLK0_On
			);
		case Generator_Running_CLK1_Off : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING_CLK1_OFF] == Generator_Running_CLK1_Off
			);
		case Generator_Running_CLK1_On : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING_CLK1_ON] == Generator_Running_CLK1_On
			);
		case Generator_Running_CLK2_Off : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING_CLK2_OFF] == Generator_Running_CLK2_Off
			);
		case Generator_Running_CLK2_On : 
			return (sc_boolean) (stateConfVector[SCVI_GENERATOR_RUNNING_CLK2_ON] == Generator_Running_CLK2_On
			);
		default: return false;
	}
}

Default::DefaultSCI* Default::getDefaultSCI()
{
	return &iface;
}
/* Functions for event eReady in interface DefaultSCI */
void Default::DefaultSCI::raise_eReady()
{
	eReady_raised = true;
}
void Default::raise_eReady()
{
	iface.raise_eReady();
}
/* Functions for event eShortPress in interface DefaultSCI */
void Default::DefaultSCI::raise_eShortPress()
{
	eShortPress_raised = true;
}
void Default::raise_eShortPress()
{
	iface.raise_eShortPress();
}
/* Functions for event eLongPress in interface DefaultSCI */
void Default::DefaultSCI::raise_eLongPress()
{
	eLongPress_raised = true;
}
void Default::raise_eLongPress()
{
	iface.raise_eLongPress();
}
/* Functions for event eClockWiseTick in interface DefaultSCI */
void Default::DefaultSCI::raise_eClockWiseTick(sc_integer value)
{
	eClockWiseTick_value = value;
	eClockWiseTick_raised = true;
}
void Default::raise_eClockWiseTick(sc_integer value)
{
	iface.raise_eClockWiseTick(value);
}
/* Functions for event eCounterClockWiseTick in interface DefaultSCI */
void Default::DefaultSCI::raise_eCounterClockWiseTick(sc_integer value)
{
	eCounterClockWiseTick_value = value;
	eCounterClockWiseTick_raised = true;
}
void Default::raise_eCounterClockWiseTick(sc_integer value)
{
	iface.raise_eCounterClockWiseTick(value);
}
/* Functions for event eUpdateDisplay in interface DefaultSCI */
void Default::DefaultSCI::raise_eUpdateDisplay()
{
	eUpdateDisplay_raised = true;
}
void Default::raise_eUpdateDisplay()
{
	iface.raise_eUpdateDisplay();
}
sc_integer Default::DefaultSCI::get_clock0Freq() const
{
	return clock0Freq;
}

sc_integer Default::get_clock0Freq() const
{
	return iface.clock0Freq;
}

void Default::DefaultSCI::set_clock0Freq(sc_integer value)
{
	clock0Freq = value;
}

void Default::set_clock0Freq(sc_integer value)
{
	iface.clock0Freq = value;
}

sc_integer Default::DefaultSCI::get_clock1Freq() const
{
	return clock1Freq;
}

sc_integer Default::get_clock1Freq() const
{
	return iface.clock1Freq;
}

void Default::DefaultSCI::set_clock1Freq(sc_integer value)
{
	clock1Freq = value;
}

void Default::set_clock1Freq(sc_integer value)
{
	iface.clock1Freq = value;
}

sc_integer Default::DefaultSCI::get_clock2Freq() const
{
	return clock2Freq;
}

sc_integer Default::get_clock2Freq() const
{
	return iface.clock2Freq;
}

void Default::DefaultSCI::set_clock2Freq(sc_integer value)
{
	clock2Freq = value;
}

void Default::set_clock2Freq(sc_integer value)
{
	iface.clock2Freq = value;
}

sc_integer Default::DefaultSCI::get_clock0ReqFreq() const
{
	return clock0ReqFreq;
}

sc_integer Default::get_clock0ReqFreq() const
{
	return iface.clock0ReqFreq;
}

void Default::DefaultSCI::set_clock0ReqFreq(sc_integer value)
{
	clock0ReqFreq = value;
}

void Default::set_clock0ReqFreq(sc_integer value)
{
	iface.clock0ReqFreq = value;
}

sc_integer Default::DefaultSCI::get_clock1ReqFreq() const
{
	return clock1ReqFreq;
}

sc_integer Default::get_clock1ReqFreq() const
{
	return iface.clock1ReqFreq;
}

void Default::DefaultSCI::set_clock1ReqFreq(sc_integer value)
{
	clock1ReqFreq = value;
}

void Default::set_clock1ReqFreq(sc_integer value)
{
	iface.clock1ReqFreq = value;
}

sc_integer Default::DefaultSCI::get_clock2ReqFreq() const
{
	return clock2ReqFreq;
}

sc_integer Default::get_clock2ReqFreq() const
{
	return iface.clock2ReqFreq;
}

void Default::DefaultSCI::set_clock2ReqFreq(sc_integer value)
{
	clock2ReqFreq = value;
}

void Default::set_clock2ReqFreq(sc_integer value)
{
	iface.clock2ReqFreq = value;
}

sc_integer Default::DefaultSCI::get_clock0Multiplier() const
{
	return clock0Multiplier;
}

sc_integer Default::get_clock0Multiplier() const
{
	return iface.clock0Multiplier;
}

void Default::DefaultSCI::set_clock0Multiplier(sc_integer value)
{
	clock0Multiplier = value;
}

void Default::set_clock0Multiplier(sc_integer value)
{
	iface.clock0Multiplier = value;
}

sc_integer Default::DefaultSCI::get_clock1Multiplier() const
{
	return clock1Multiplier;
}

sc_integer Default::get_clock1Multiplier() const
{
	return iface.clock1Multiplier;
}

void Default::DefaultSCI::set_clock1Multiplier(sc_integer value)
{
	clock1Multiplier = value;
}

void Default::set_clock1Multiplier(sc_integer value)
{
	iface.clock1Multiplier = value;
}

sc_integer Default::DefaultSCI::get_clock2Multiplier() const
{
	return clock2Multiplier;
}

sc_integer Default::get_clock2Multiplier() const
{
	return iface.clock2Multiplier;
}

void Default::DefaultSCI::set_clock2Multiplier(sc_integer value)
{
	clock2Multiplier = value;
}

void Default::set_clock2Multiplier(sc_integer value)
{
	iface.clock2Multiplier = value;
}

void Default::setDefaultSCI_OCB(DefaultSCI_OCB* operationCallback)
{
	iface_OCB = operationCallback;
}
/* Functions for event eGeneratorInitialized in interface InternalSCI */
void Default::InternalSCI::raise_eGeneratorInitialized()
{
	eGeneratorInitialized_raised = true;
}
sc_boolean Default::InternalSCI::isRaised_eGeneratorInitialized() const
{
	return eGeneratorInitialized_raised;
}
/* Functions for event eClock0Toggle in interface InternalSCI */
void Default::InternalSCI::raise_eClock0Toggle()
{
	eClock0Toggle_raised = true;
}
sc_boolean Default::InternalSCI::isRaised_eClock0Toggle() const
{
	return eClock0Toggle_raised;
}
/* Functions for event eClock1Toggle in interface InternalSCI */
void Default::InternalSCI::raise_eClock1Toggle()
{
	eClock1Toggle_raised = true;
}
sc_boolean Default::InternalSCI::isRaised_eClock1Toggle() const
{
	return eClock1Toggle_raised;
}
/* Functions for event eClock2Toggle in interface InternalSCI */
void Default::InternalSCI::raise_eClock2Toggle()
{
	eClock2Toggle_raised = true;
}
sc_boolean Default::InternalSCI::isRaised_eClock2Toggle() const
{
	return eClock2Toggle_raised;
}
/* Functions for event eClockUpdate in interface InternalSCI */
void Default::InternalSCI::raise_eClockUpdate()
{
	eClockUpdate_raised = true;
}
sc_boolean Default::InternalSCI::isRaised_eClockUpdate() const
{
	return eClockUpdate_raised;
}

// implementations of all internal functions

/* Entry action for state 'initialize'. */
void Default::enact_main_region_initialize()
{
	/* Entry action for state 'initialize'. */
	iface_OCB->updateDisplay();
	iface.eReady_raised = true;
}

/* Entry action for state 'Initialize'. */
void Default::enact_Generator_Initialize()
{
	/* Entry action for state 'Initialize'. */
	ifaceInternalSCI.eGeneratorInitialized_raised = true;
}

/* Entry action for state 'Off'. */
void Default::enact_Generator_Running_CLK0_Off()
{
	/* Entry action for state 'Off'. */
	iface_OCB->disableClock(0);
}

/* Entry action for state 'On'. */
void Default::enact_Generator_Running_CLK0_On()
{
	/* Entry action for state 'On'. */
	iface_OCB->updateClock(0);
	iface_OCB->enableClock(0);
}

/* Entry action for state 'Off'. */
void Default::enact_Generator_Running_CLK1_Off()
{
	/* Entry action for state 'Off'. */
	iface_OCB->disableClock(1);
}

/* Entry action for state 'On'. */
void Default::enact_Generator_Running_CLK1_On()
{
	/* Entry action for state 'On'. */
	iface_OCB->updateClock(1);
	iface_OCB->enableClock(1);
}

/* Entry action for state 'Off'. */
void Default::enact_Generator_Running_CLK2_Off()
{
	/* Entry action for state 'Off'. */
	iface_OCB->disableClock(2);
}

/* Entry action for state 'On'. */
void Default::enact_Generator_Running_CLK2_On()
{
	/* Entry action for state 'On'. */
	iface_OCB->updateClock(2);
	iface_OCB->enableClock(2);
}

/* 'default' enter sequence for state initialize */
void Default::enseq_main_region_initialize_default()
{
	/* 'default' enter sequence for state initialize */
	enact_main_region_initialize();
	stateConfVector[0] = main_region_initialize;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state main */
void Default::enseq_main_region_main_default()
{
	/* 'default' enter sequence for state main */
	enseq_main_region_main_r1_default();
}

/* 'default' enter sequence for state menubar */
void Default::enseq_main_region_main_r1_menubar_default()
{
	/* 'default' enter sequence for state menubar */
	stateConfVector[0] = main_region_main_r1_menubar;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state freq0bar */
void Default::enseq_main_region_main_r1_freq0bar_default()
{
	/* 'default' enter sequence for state freq0bar */
	enseq_main_region_main_r1_freq0bar_clk0_default();
}

/* 'default' enter sequence for state Highlighted */
void Default::enseq_main_region_main_r1_freq0bar_clk0_Highlighted_default()
{
	/* 'default' enter sequence for state Highlighted */
	stateConfVector[0] = main_region_main_r1_freq0bar_clk0_Highlighted;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Selected */
void Default::enseq_main_region_main_r1_freq0bar_clk0_Selected_default()
{

	/* 'default' enter sequence for state Selected */
	stateConfVector[0] = main_region_main_r1_freq0bar_clk0_Selected;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SetMultiplier */
void Default::enseq_main_region_main_r1_freq0bar_clk0_SetMultiplier_default()
{
	/* 'default' enter sequence for state SetMultiplier */
	stateConfVector[0] = main_region_main_r1_freq0bar_clk0_SetMultiplier;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state freq1bar */
void Default::enseq_main_region_main_r1_freq1bar_default()
{
	/* 'default' enter sequence for state freq1bar */
	enseq_main_region_main_r1_freq1bar_clk1_default();
}

/* 'default' enter sequence for state Highlighted */
void Default::enseq_main_region_main_r1_freq1bar_clk1_Highlighted_default()
{
	/* 'default' enter sequence for state Highlighted */
	stateConfVector[0] = main_region_main_r1_freq1bar_clk1_Highlighted;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Selected */
void Default::enseq_main_region_main_r1_freq1bar_clk1_Selected_default()
{
	/* 'default' enter sequence for state Selected */
	stateConfVector[0] = main_region_main_r1_freq1bar_clk1_Selected;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SetMultiplier */
void Default::enseq_main_region_main_r1_freq1bar_clk1_SetMultiplier_default()
{
	/* 'default' enter sequence for state SetMultiplier */
	stateConfVector[0] = main_region_main_r1_freq1bar_clk1_SetMultiplier;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state freq2bar */
void Default::enseq_main_region_main_r1_freq2bar_default()
{
	/* 'default' enter sequence for state freq2bar */
	enseq_main_region_main_r1_freq2bar_clk2_default();
}

/* 'default' enter sequence for state Highlighted */
void Default::enseq_main_region_main_r1_freq2bar_clk2_Highlighted_default()
{
	/* 'default' enter sequence for state Highlighted */
	stateConfVector[0] = main_region_main_r1_freq2bar_clk2_Highlighted;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Selected */
void Default::enseq_main_region_main_r1_freq2bar_clk2_Selected_default()
{
	/* 'default' enter sequence for state Selected */
	stateConfVector[0] = main_region_main_r1_freq2bar_clk2_Selected;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state SetMultiplier */
void Default::enseq_main_region_main_r1_freq2bar_clk2_SetMultiplier_default()
{
	/* 'default' enter sequence for state SetMultiplier */
	stateConfVector[0] = main_region_main_r1_freq2bar_clk2_SetMultiplier;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state Initialize */
void Default::enseq_Generator_Initialize_default()
{
	/* 'default' enter sequence for state Initialize */
	enact_Generator_Initialize();
	stateConfVector[1] = Generator_Initialize;
	stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Running */
void Default::enseq_Generator_Running_default()
{
	/* 'default' enter sequence for state Running */
	enseq_Generator_Running_CLK0_default();
	enseq_Generator_Running_CLK1_default();
	enseq_Generator_Running_CLK2_default();
}

/* 'default' enter sequence for state Off */
void Default::enseq_Generator_Running_CLK0_Off_default()
{
	/* 'default' enter sequence for state Off */
	enact_Generator_Running_CLK0_Off();
	stateConfVector[1] = Generator_Running_CLK0_Off;
	stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state On */
void Default::enseq_Generator_Running_CLK0_On_default()
{
	/* 'default' enter sequence for state On */
	enact_Generator_Running_CLK0_On();
	stateConfVector[1] = Generator_Running_CLK0_On;
	stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state Off */
void Default::enseq_Generator_Running_CLK1_Off_default()
{
	/* 'default' enter sequence for state Off */
	enact_Generator_Running_CLK1_Off();
	stateConfVector[2] = Generator_Running_CLK1_Off;
	stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state On */
void Default::enseq_Generator_Running_CLK1_On_default()
{
	/* 'default' enter sequence for state On */
	enact_Generator_Running_CLK1_On();
	stateConfVector[2] = Generator_Running_CLK1_On;
	stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state Off */
void Default::enseq_Generator_Running_CLK2_Off_default()
{
	/* 'default' enter sequence for state Off */
	enact_Generator_Running_CLK2_Off();
	stateConfVector[3] = Generator_Running_CLK2_Off;
	stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state On */
void Default::enseq_Generator_Running_CLK2_On_default()
{
	/* 'default' enter sequence for state On */
	enact_Generator_Running_CLK2_On();
	stateConfVector[3] = Generator_Running_CLK2_On;
	stateConfVectorPosition = 3;
}

/* 'default' enter sequence for region main region */
void Default::enseq_main_region_default()
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default();
}

/* 'default' enter sequence for region r1 */
void Default::enseq_main_region_main_r1_default()
{
	/* 'default' enter sequence for region r1 */
	react_main_region_main_r1__entry_Default();
}

/* 'default' enter sequence for region clk0 */
void Default::enseq_main_region_main_r1_freq0bar_clk0_default()
{
	/* 'default' enter sequence for region clk0 */
	react_main_region_main_r1_freq0bar_clk0__entry_Default();
}

/* 'default' enter sequence for region clk1 */
void Default::enseq_main_region_main_r1_freq1bar_clk1_default()
{
	/* 'default' enter sequence for region clk1 */
	react_main_region_main_r1_freq1bar_clk1__entry_Default();
}

/* 'default' enter sequence for region clk2 */
void Default::enseq_main_region_main_r1_freq2bar_clk2_default()
{
	/* 'default' enter sequence for region clk2 */
	react_main_region_main_r1_freq2bar_clk2__entry_Default();
}

/* 'default' enter sequence for region Generator */
void Default::enseq_Generator_default()
{
	/* 'default' enter sequence for region Generator */
	react_Generator__entry_Default();
}

/* 'default' enter sequence for region CLK0 */
void Default::enseq_Generator_Running_CLK0_default()
{
	/* 'default' enter sequence for region CLK0 */
	react_Generator_Running_CLK0__entry_Default();
}

/* 'default' enter sequence for region CLK1 */
void Default::enseq_Generator_Running_CLK1_default()
{
	/* 'default' enter sequence for region CLK1 */
	react_Generator_Running_CLK1__entry_Default();
}

/* 'default' enter sequence for region CLK2 */
void Default::enseq_Generator_Running_CLK2_default()
{
	/* 'default' enter sequence for region CLK2 */
	react_Generator_Running_CLK2__entry_Default();
}

/* Default exit sequence for state initialize */
void Default::exseq_main_region_initialize()
{
	/* Default exit sequence for state initialize */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state main */
void Default::exseq_main_region_main()
{
	/* Default exit sequence for state main */
	exseq_main_region_main_r1();
}

/* Default exit sequence for state menubar */
void Default::exseq_main_region_main_r1_menubar()
{
	/* Default exit sequence for state menubar */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state freq0bar */
void Default::exseq_main_region_main_r1_freq0bar()
{
	/* Default exit sequence for state freq0bar */
	exseq_main_region_main_r1_freq0bar_clk0();
}

/* Default exit sequence for state Highlighted */
void Default::exseq_main_region_main_r1_freq0bar_clk0_Highlighted()
{
	/* Default exit sequence for state Highlighted */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state Selected */
void Default::exseq_main_region_main_r1_freq0bar_clk0_Selected()
{
	/* Default exit sequence for state Selected */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SetMultiplier */
void Default::exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier()
{
	/* Default exit sequence for state SetMultiplier */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state freq1bar */
void Default::exseq_main_region_main_r1_freq1bar()
{
	/* Default exit sequence for state freq1bar */
	exseq_main_region_main_r1_freq1bar_clk1();
}

/* Default exit sequence for state Highlighted */
void Default::exseq_main_region_main_r1_freq1bar_clk1_Highlighted()
{
	/* Default exit sequence for state Highlighted */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state Selected */
void Default::exseq_main_region_main_r1_freq1bar_clk1_Selected()
{
	/* Default exit sequence for state Selected */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SetMultiplier */
void Default::exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier()
{
	/* Default exit sequence for state SetMultiplier */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state freq2bar */
void Default::exseq_main_region_main_r1_freq2bar()
{
	/* Default exit sequence for state freq2bar */
	exseq_main_region_main_r1_freq2bar_clk2();
}

/* Default exit sequence for state Highlighted */
void Default::exseq_main_region_main_r1_freq2bar_clk2_Highlighted()
{
	/* Default exit sequence for state Highlighted */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state Selected */
void Default::exseq_main_region_main_r1_freq2bar_clk2_Selected()
{
	/* Default exit sequence for state Selected */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state SetMultiplier */
void Default::exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier()
{
	/* Default exit sequence for state SetMultiplier */
	stateConfVector[0] = Default_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state Initialize */
void Default::exseq_Generator_Initialize()
{
	/* Default exit sequence for state Initialize */
	stateConfVector[1] = Default_last_state;
	stateConfVectorPosition = 1;
}

/* Default exit sequence for state Off */
void Default::exseq_Generator_Running_CLK0_Off()
{
	/* Default exit sequence for state Off */
	stateConfVector[1] = Default_last_state;
	stateConfVectorPosition = 1;
}

/* Default exit sequence for state On */
void Default::exseq_Generator_Running_CLK0_On()
{
	/* Default exit sequence for state On */
	stateConfVector[1] = Default_last_state;
	stateConfVectorPosition = 1;
}

/* Default exit sequence for state Off */
void Default::exseq_Generator_Running_CLK1_Off()
{
	/* Default exit sequence for state Off */
	stateConfVector[2] = Default_last_state;
	stateConfVectorPosition = 2;
}

/* Default exit sequence for state On */
void Default::exseq_Generator_Running_CLK1_On()
{
	/* Default exit sequence for state On */
	stateConfVector[2] = Default_last_state;
	stateConfVectorPosition = 2;
}

/* Default exit sequence for state Off */
void Default::exseq_Generator_Running_CLK2_Off()
{
	/* Default exit sequence for state Off */
	stateConfVector[3] = Default_last_state;
	stateConfVectorPosition = 3;
}

/* Default exit sequence for state On */
void Default::exseq_Generator_Running_CLK2_On()
{
	/* Default exit sequence for state On */
	stateConfVector[3] = Default_last_state;
	stateConfVectorPosition = 3;
}

/* Default exit sequence for region main region */
void Default::exseq_main_region()
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of default.main_region) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_initialize :
		{
			exseq_main_region_initialize();
			break;
		}
		case main_region_main_r1_menubar :
		{
			exseq_main_region_main_r1_menubar();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Highlighted :
		{
			exseq_main_region_main_r1_freq0bar_clk0_Highlighted();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Selected :
		{
			exseq_main_region_main_r1_freq0bar_clk0_Selected();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_SetMultiplier :
		{
			exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Highlighted :
		{
			exseq_main_region_main_r1_freq1bar_clk1_Highlighted();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Selected :
		{
			exseq_main_region_main_r1_freq1bar_clk1_Selected();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_SetMultiplier :
		{
			exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Highlighted :
		{
			exseq_main_region_main_r1_freq2bar_clk2_Highlighted();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Selected :
		{
			exseq_main_region_main_r1_freq2bar_clk2_Selected();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_SetMultiplier :
		{
			exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
void Default::exseq_main_region_main_r1()
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of default.main_region.main.r1) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_main_r1_menubar :
		{
			exseq_main_region_main_r1_menubar();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Highlighted :
		{
			exseq_main_region_main_r1_freq0bar_clk0_Highlighted();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Selected :
		{
			exseq_main_region_main_r1_freq0bar_clk0_Selected();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_SetMultiplier :
		{
			exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Highlighted :
		{
			exseq_main_region_main_r1_freq1bar_clk1_Highlighted();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Selected :
		{
			exseq_main_region_main_r1_freq1bar_clk1_Selected();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_SetMultiplier :
		{
			exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Highlighted :
		{
			exseq_main_region_main_r1_freq2bar_clk2_Highlighted();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Selected :
		{
			exseq_main_region_main_r1_freq2bar_clk2_Selected();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_SetMultiplier :
		{
			exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region clk0 */
void Default::exseq_main_region_main_r1_freq0bar_clk0()
{
	/* Default exit sequence for region clk0 */
	/* Handle exit of all possible states (of default.main_region.main.r1.freq0bar.clk0) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_main_r1_freq0bar_clk0_Highlighted :
		{
			exseq_main_region_main_r1_freq0bar_clk0_Highlighted();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_Selected :
		{
			exseq_main_region_main_r1_freq0bar_clk0_Selected();
			break;
		}
		case main_region_main_r1_freq0bar_clk0_SetMultiplier :
		{
			exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region clk1 */
void Default::exseq_main_region_main_r1_freq1bar_clk1()
{
	/* Default exit sequence for region clk1 */
	/* Handle exit of all possible states (of default.main_region.main.r1.freq1bar.clk1) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_main_r1_freq1bar_clk1_Highlighted :
		{
			exseq_main_region_main_r1_freq1bar_clk1_Highlighted();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_Selected :
		{
			exseq_main_region_main_r1_freq1bar_clk1_Selected();
			break;
		}
		case main_region_main_r1_freq1bar_clk1_SetMultiplier :
		{
			exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region clk2 */
void Default::exseq_main_region_main_r1_freq2bar_clk2()
{
	/* Default exit sequence for region clk2 */
	/* Handle exit of all possible states (of default.main_region.main.r1.freq2bar.clk2) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_main_r1_freq2bar_clk2_Highlighted :
		{
			exseq_main_region_main_r1_freq2bar_clk2_Highlighted();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_Selected :
		{
			exseq_main_region_main_r1_freq2bar_clk2_Selected();
			break;
		}
		case main_region_main_r1_freq2bar_clk2_SetMultiplier :
		{
			exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Generator */
void Default::exseq_Generator()
{
	/* Default exit sequence for region Generator */
	/* Handle exit of all possible states (of default.Generator) at position 1... */
	switch(stateConfVector[ 1 ])
	{
		case Generator_Initialize :
		{
			exseq_Generator_Initialize();
			break;
		}
		case Generator_Running_CLK0_Off :
		{
			exseq_Generator_Running_CLK0_Off();
			break;
		}
		case Generator_Running_CLK0_On :
		{
			exseq_Generator_Running_CLK0_On();
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of default.Generator) at position 2... */
	switch(stateConfVector[ 2 ])
	{
		case Generator_Running_CLK1_Off :
		{
			exseq_Generator_Running_CLK1_Off();
			break;
		}
		case Generator_Running_CLK1_On :
		{
			exseq_Generator_Running_CLK1_On();
			break;
		}
		default: break;
	}
	/* Handle exit of all possible states (of default.Generator) at position 3... */
	switch(stateConfVector[ 3 ])
	{
		case Generator_Running_CLK2_Off :
		{
			exseq_Generator_Running_CLK2_Off();
			break;
		}
		case Generator_Running_CLK2_On :
		{
			exseq_Generator_Running_CLK2_On();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region CLK0 */
void Default::exseq_Generator_Running_CLK0()
{
	/* Default exit sequence for region CLK0 */
	/* Handle exit of all possible states (of default.Generator.Running.CLK0) at position 1... */
	switch(stateConfVector[ 1 ])
	{
		case Generator_Running_CLK0_Off :
		{
			exseq_Generator_Running_CLK0_Off();
			break;
		}
		case Generator_Running_CLK0_On :
		{
			exseq_Generator_Running_CLK0_On();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region CLK1 */
void Default::exseq_Generator_Running_CLK1()
{
	/* Default exit sequence for region CLK1 */
	/* Handle exit of all possible states (of default.Generator.Running.CLK1) at position 2... */
	switch(stateConfVector[ 2 ])
	{
		case Generator_Running_CLK1_Off :
		{
			exseq_Generator_Running_CLK1_Off();
			break;
		}
		case Generator_Running_CLK1_On :
		{
			exseq_Generator_Running_CLK1_On();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region CLK2 */
void Default::exseq_Generator_Running_CLK2()
{
	/* Default exit sequence for region CLK2 */
	/* Handle exit of all possible states (of default.Generator.Running.CLK2) at position 3... */
	switch(stateConfVector[ 3 ])
	{
		case Generator_Running_CLK2_Off :
		{
			exseq_Generator_Running_CLK2_Off();
			break;
		}
		case Generator_Running_CLK2_On :
		{
			exseq_Generator_Running_CLK2_On();
			break;
		}
		default: break;
	}
}

/* Default react sequence for initial entry  */
void Default::react_main_region__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_initialize_default();
}

/* Default react sequence for initial entry  */
void Default::react_main_region_main_r1_freq0bar_clk0__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_main_r1_freq0bar_clk0_Highlighted_default();
}

/* Default react sequence for initial entry  */
void Default::react_main_region_main_r1_freq1bar_clk1__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_main_r1_freq1bar_clk1_Highlighted_default();
}

/* Default react sequence for initial entry  */
void Default::react_main_region_main_r1_freq2bar_clk2__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_main_r1_freq2bar_clk2_Highlighted_default();
}

/* Default react sequence for initial entry  */
void Default::react_main_region_main_r1__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_main_r1_freq0bar_default();
}

/* Default react sequence for initial entry  */
void Default::react_Generator__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_Generator_Initialize_default();
}

/* Default react sequence for initial entry  */
void Default::react_Generator_Running_CLK0__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_Generator_Running_CLK0_Off_default();
}

/* Default react sequence for initial entry  */
void Default::react_Generator_Running_CLK1__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_Generator_Running_CLK1_Off_default();
}

/* Default react sequence for initial entry  */
void Default::react_Generator_Running_CLK2__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_Generator_Running_CLK2_Off_default();
}

sc_boolean Default::react(const sc_boolean try_transition) {
	/* State machine reactions. */
	return false;
}

sc_boolean Default::main_region_initialize_react(const sc_boolean try_transition) {
	/* The reactions of state initialize. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eReady_raised)
		{ 
			exseq_main_region_initialize();
			enseq_main_region_main_default();
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_react(const sc_boolean try_transition) {
	/* The reactions of state main. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eUpdateDisplay_raised)
		{ 
			exseq_main_region_main();
			iface_OCB->updateDisplay();
			enseq_main_region_main_default();
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_menubar_react(const sc_boolean try_transition) {
	/* The reactions of state menubar. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eCounterClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_menubar();
			enseq_main_region_main_r1_freq2bar_default();
			main_region_main_react(false);
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq0bar_react(const sc_boolean try_transition) {
	/* The reactions of state freq0bar. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eCounterClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_freq0bar();
			enseq_main_region_main_r1_menubar_default();
			main_region_main_react(false);
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq0bar();
				enseq_main_region_main_r1_freq1bar_default();
				main_region_main_react(false);
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq0bar_clk0_Highlighted_react(const sc_boolean try_transition) {
	/* The reactions of state Highlighted. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eLongPress_raised)
		{ 
			exseq_main_region_main_r1_freq0bar_clk0_Highlighted();
			enseq_main_region_main_r1_freq0bar_clk0_Selected_default();
			main_region_main_r1_freq0bar_react(false);
		}  else
		{
			if (iface.eShortPress_raised)
			{ 
				exseq_main_region_main_r1_freq0bar_clk0_Highlighted();
				ifaceInternalSCI.eClock0Toggle_raised = true;
				enseq_main_region_main_r1_freq0bar_clk0_Highlighted_default();
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq0bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq0bar_clk0_Selected_react(const sc_boolean try_transition) {
	/* The reactions of state Selected. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eCounterClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_freq0bar_clk0_Selected();
			iface.clock0ReqFreq = iface.clock0ReqFreq - iface.clock0Multiplier;
			ifaceInternalSCI.eClockUpdate_raised = true;
			enseq_main_region_main_r1_freq0bar_clk0_Selected_default();
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq0bar_clk0_Selected();
				iface.clock0ReqFreq = iface.clock0ReqFreq + iface.clock0Multiplier;
				ifaceInternalSCI.eClockUpdate_raised = true;
				enseq_main_region_main_r1_freq0bar_clk0_Selected_default();
			}  else
			{
				if (iface.eLongPress_raised)
				{ 
					exseq_main_region_main_r1_freq0bar_clk0_Selected();
					enseq_main_region_main_r1_freq0bar_clk0_Highlighted_default();
					main_region_main_r1_freq0bar_react(false);
				}  else
				{
					if (iface.eShortPress_raised)
					{ 
						exseq_main_region_main_r1_freq0bar_clk0_Selected();
						enseq_main_region_main_r1_freq0bar_clk0_SetMultiplier_default();
						main_region_main_r1_freq0bar_react(false);
					}  else
					{
						did_transition = false;
					}
				}
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq0bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq0bar_clk0_SetMultiplier_react(const sc_boolean try_transition) {
	/* The reactions of state SetMultiplier. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eShortPress_raised)
		{ 
			exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
			enseq_main_region_main_r1_freq0bar_clk0_Selected_default();
			main_region_main_r1_freq0bar_react(false);
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
				iface.clock0Multiplier = ((iface.clock0Multiplier) != (1)) ? iface.clock0Multiplier / 10 : iface.clock0Multiplier;
				enseq_main_region_main_r1_freq0bar_clk0_SetMultiplier_default();
			}  else
			{
				if (iface.eCounterClockWiseTick_raised)
				{ 
					exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
					iface.clock0Multiplier = ((iface.clock0Multiplier) != (1000000)) ? iface.clock0Multiplier * 10 : iface.clock0Multiplier;
					enseq_main_region_main_r1_freq0bar_clk0_SetMultiplier_default();
				}  else
				{
					if (iface.eLongPress_raised)
					{ 
						exseq_main_region_main_r1_freq0bar_clk0_SetMultiplier();
						enseq_main_region_main_r1_freq0bar_clk0_Highlighted_default();
						main_region_main_r1_freq0bar_react(false);
					}  else
					{
						did_transition = false;
					}
				}
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq0bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq1bar_react(const sc_boolean try_transition) {
	/* The reactions of state freq1bar. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_freq1bar();
			enseq_main_region_main_r1_freq2bar_default();
			main_region_main_react(false);
		}  else
		{
			if (iface.eCounterClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq1bar();
				enseq_main_region_main_r1_freq0bar_default();
				main_region_main_react(false);
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq1bar_clk1_Highlighted_react(const sc_boolean try_transition) {
	/* The reactions of state Highlighted. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eLongPress_raised)
		{ 
			exseq_main_region_main_r1_freq1bar_clk1_Highlighted();
			enseq_main_region_main_r1_freq1bar_clk1_Selected_default();
			main_region_main_r1_freq1bar_react(false);
		}  else
		{
			if (iface.eShortPress_raised)
			{ 
				exseq_main_region_main_r1_freq1bar_clk1_Highlighted();
				ifaceInternalSCI.eClock1Toggle_raised = true;
				enseq_main_region_main_r1_freq1bar_clk1_Highlighted_default();
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq1bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq1bar_clk1_Selected_react(const sc_boolean try_transition) {
	/* The reactions of state Selected. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eCounterClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_freq1bar_clk1_Selected();
			iface.clock1ReqFreq = iface.clock1ReqFreq - iface.clock1Multiplier;
			ifaceInternalSCI.eClockUpdate_raised = true;
			enseq_main_region_main_r1_freq1bar_clk1_Selected_default();
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq1bar_clk1_Selected();
				iface.clock1ReqFreq = iface.clock1ReqFreq + iface.clock1Multiplier;
				ifaceInternalSCI.eClockUpdate_raised = true;
				enseq_main_region_main_r1_freq1bar_clk1_Selected_default();
			}  else
			{
				if (iface.eLongPress_raised)
				{ 
					exseq_main_region_main_r1_freq1bar_clk1_Selected();
					enseq_main_region_main_r1_freq1bar_clk1_Highlighted_default();
					main_region_main_r1_freq1bar_react(false);
				}  else
				{
					if (iface.eShortPress_raised)
					{ 
						exseq_main_region_main_r1_freq1bar_clk1_Selected();
						enseq_main_region_main_r1_freq1bar_clk1_SetMultiplier_default();
						main_region_main_r1_freq1bar_react(false);
					}  else
					{
						did_transition = false;
					}
				}
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq1bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq1bar_clk1_SetMultiplier_react(const sc_boolean try_transition) {
	/* The reactions of state SetMultiplier. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eShortPress_raised)
		{ 
			exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
			enseq_main_region_main_r1_freq1bar_clk1_Selected_default();
			main_region_main_r1_freq1bar_react(false);
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
				iface.clock1Multiplier = ((iface.clock1Multiplier) != (1)) ? iface.clock1Multiplier / 10 : iface.clock1Multiplier;
				enseq_main_region_main_r1_freq1bar_clk1_SetMultiplier_default();
			}  else
			{
				if (iface.eCounterClockWiseTick_raised)
				{ 
					exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
					iface.clock1Multiplier = ((iface.clock1Multiplier) != (1000000)) ? iface.clock1Multiplier * 10 : iface.clock1Multiplier;
					enseq_main_region_main_r1_freq1bar_clk1_SetMultiplier_default();
				}  else
				{
					if (iface.eLongPress_raised)
					{ 
						exseq_main_region_main_r1_freq1bar_clk1_SetMultiplier();
						enseq_main_region_main_r1_freq1bar_clk1_Highlighted_default();
						main_region_main_r1_freq1bar_react(false);
					}  else
					{
						did_transition = false;
					}
				}
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq1bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq2bar_react(const sc_boolean try_transition) {
	/* The reactions of state freq2bar. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_freq2bar();
			enseq_main_region_main_r1_menubar_default();
			main_region_main_react(false);
		}  else
		{
			if (iface.eCounterClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq2bar();
				enseq_main_region_main_r1_freq1bar_default();
				main_region_main_react(false);
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq2bar_clk2_Highlighted_react(const sc_boolean try_transition) {
	/* The reactions of state Highlighted. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eLongPress_raised)
		{ 
			exseq_main_region_main_r1_freq2bar_clk2_Highlighted();
			enseq_main_region_main_r1_freq2bar_clk2_Selected_default();
			main_region_main_r1_freq2bar_react(false);
		}  else
		{
			if (iface.eShortPress_raised)
			{ 
				exseq_main_region_main_r1_freq2bar_clk2_Highlighted();
				ifaceInternalSCI.eClock2Toggle_raised = true;
				enseq_main_region_main_r1_freq2bar_clk2_Highlighted_default();
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq2bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq2bar_clk2_Selected_react(const sc_boolean try_transition) {
	/* The reactions of state Selected. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eCounterClockWiseTick_raised)
		{ 
			exseq_main_region_main_r1_freq2bar_clk2_Selected();
			iface.clock2ReqFreq = iface.clock2ReqFreq - iface.clock2Multiplier;
			ifaceInternalSCI.eClockUpdate_raised = true;
			enseq_main_region_main_r1_freq2bar_clk2_Selected_default();
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq2bar_clk2_Selected();
				iface.clock2ReqFreq = iface.clock2ReqFreq + iface.clock2Multiplier;
				ifaceInternalSCI.eClockUpdate_raised = true;
				enseq_main_region_main_r1_freq2bar_clk2_Selected_default();
			}  else
			{
				if (iface.eLongPress_raised)
				{ 
					exseq_main_region_main_r1_freq2bar_clk2_Selected();
					enseq_main_region_main_r1_freq2bar_clk2_Highlighted_default();
					main_region_main_r1_freq2bar_react(false);
				}  else
				{
					if (iface.eShortPress_raised)
					{ 
						exseq_main_region_main_r1_freq2bar_clk2_Selected();
						enseq_main_region_main_r1_freq2bar_clk2_SetMultiplier_default();
						main_region_main_r1_freq2bar_react(false);
					}  else
					{
						did_transition = false;
					}
				}
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq2bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::main_region_main_r1_freq2bar_clk2_SetMultiplier_react(const sc_boolean try_transition) {
	/* The reactions of state SetMultiplier. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (iface.eShortPress_raised)
		{ 
			exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
			enseq_main_region_main_r1_freq2bar_clk2_Selected_default();
			main_region_main_r1_freq2bar_react(false);
		}  else
		{
			if (iface.eClockWiseTick_raised)
			{ 
				exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
				iface.clock2Multiplier = ((iface.clock2Multiplier) != (1)) ? iface.clock2Multiplier / 10 : iface.clock2Multiplier;
				enseq_main_region_main_r1_freq2bar_clk2_SetMultiplier_default();
			}  else
			{
				if (iface.eCounterClockWiseTick_raised)
				{ 
					exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
					iface.clock2Multiplier = ((iface.clock2Multiplier) != (1000000)) ? iface.clock2Multiplier * 10 : iface.clock2Multiplier;
					enseq_main_region_main_r1_freq2bar_clk2_SetMultiplier_default();
				}  else
				{
					if (iface.eLongPress_raised)
					{ 
						exseq_main_region_main_r1_freq2bar_clk2_SetMultiplier();
						enseq_main_region_main_r1_freq2bar_clk2_Highlighted_default();
						main_region_main_r1_freq2bar_react(false);
					}  else
					{
						did_transition = false;
					}
				}
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = main_region_main_r1_freq2bar_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::Generator_Initialize_react(const sc_boolean try_transition) {
	/* The reactions of state Initialize. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eGeneratorInitialized_raised)
		{ 
			exseq_Generator_Initialize();
			enseq_Generator_Running_default();
			react(false);
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_react(const sc_boolean try_transition) {
	/* The reactions of state Running. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		did_transition = false;
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_CLK0_Off_react(const sc_boolean try_transition) {
	/* The reactions of state Off. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eClock0Toggle_raised)
		{ 
			exseq_Generator_Running_CLK0_Off();
			enseq_Generator_Running_CLK0_On_default();
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_CLK0_On_react(const sc_boolean try_transition) {
	/* The reactions of state On. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eClock0Toggle_raised)
		{ 
			exseq_Generator_Running_CLK0_On();
			enseq_Generator_Running_CLK0_Off_default();
		}  else
		{
			if (ifaceInternalSCI.eClockUpdate_raised)
			{ 
				exseq_Generator_Running_CLK0_On();
				iface_OCB->updateClock(0);
				enseq_Generator_Running_CLK0_On_default();
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_CLK1_Off_react(const sc_boolean try_transition) {
	/* The reactions of state Off. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eClock1Toggle_raised)
		{ 
			exseq_Generator_Running_CLK1_Off();
			enseq_Generator_Running_CLK1_On_default();
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_CLK1_On_react(const sc_boolean try_transition) {
	/* The reactions of state On. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eClock1Toggle_raised)
		{ 
			exseq_Generator_Running_CLK1_On();
			enseq_Generator_Running_CLK1_Off_default();
		}  else
		{
			if (ifaceInternalSCI.eClockUpdate_raised)
			{ 
				exseq_Generator_Running_CLK1_On();
				iface_OCB->updateClock(1);
				enseq_Generator_Running_CLK1_On_default();
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_CLK2_Off_react(const sc_boolean try_transition) {
	/* The reactions of state Off. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eClock2Toggle_raised)
		{ 
			exseq_Generator_Running_CLK2_Off();
			enseq_Generator_Running_CLK2_On_default();
			Generator_Running_react(false);
		}  else
		{
			did_transition = false;
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = Generator_Running_react(try_transition);
	} 
	return did_transition;
}

sc_boolean Default::Generator_Running_CLK2_On_react(const sc_boolean try_transition) {
	/* The reactions of state On. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (ifaceInternalSCI.eClock2Toggle_raised)
		{ 
			exseq_Generator_Running_CLK2_On();
			enseq_Generator_Running_CLK2_Off_default();
			Generator_Running_react(false);
		}  else
		{
			if (ifaceInternalSCI.eClockUpdate_raised)
			{ 
				exseq_Generator_Running_CLK2_On();
				iface_OCB->updateClock(2);
				enseq_Generator_Running_CLK2_On_default();
			}  else
			{
				did_transition = false;
			}
		}
	} 
	if (((did_transition) == (false)))
	{ 
		did_transition = Generator_Running_react(try_transition);
	} 
	return did_transition;
}




