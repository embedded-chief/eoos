/** 
 * Target processor interrupts factory.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef MODULE_INTERRUPT_HPP_
#define MODULE_INTERRUPT_HPP_

#include "api.Interrupt.hpp"
#include "api.Task.hpp"
#include "module.Register.hpp"
#include "Configuration.hpp"

namespace module
{
    class Interrupt : public ::api::Interrupt
    {
  
    public:
    
        /**
         * The module resource creating structure.
         */  
        struct Resource
        {
            /**
             * A pointer to a class which implements an interrupt handler interface.
             */
            ::api::Task* handler;

            /**
             * An available interrupt source.     
             */
            int32 source;

        };
        
        /** 
         * Destructor.
         */                               
        virtual ~Interrupt(){}
        
        /**
         * Sets interrupt source handler.
         *
         * @param handler pointer to user class which implements an interrupt handler interface.
         * @param source  available interrupt source.
         * @return true if handler is set successfully.
         */      
        virtual bool setHandler(::api::Task& handler, int32 source) = 0;
        
        /**
         * Removes this interrupt source handler.
         */        
        virtual void removeHandler() = 0;
        
        /**
         * Sets new registers context for storing.
         * 
         * Method sets a new register context for storing the CPU registers to it.
         * This method may be called in an user interrupt handler, it means
         * given conxet will be restored by the context restore procedure.
         *
         * @param reg new registers context.
         */
        virtual void setContext(::module::Register& reg) = 0;

        /**
         * Restores registers context for storing to the default.
         * 
         * Method restores default registers for storing the CPU registers to it.
         * This method may be called in an user interrupt handler, it means
         * the default conxet will be restored with the context restore procedure.
         */
        virtual void restoreContext() = 0;        
        
        /**
         * Returns the interrupt interface of a target processor.
         *
         * @param res the module resource creating structure.     
         * @return target processor interrupt interface.
         */
        static ::module::Interrupt* create(const ::module::Interrupt::Resource res);
        
        /**
         * Disables all maskable interrupts.
         *
         * @return global interrupts enable bit value before method was called.
         */
        static bool disableAll();
        
        /**
         * Enables all maskable interrupts.
         *
         * The true passed argument directly turns all maskable interrupts on, 
         * and the false does nothing, the interrupts stay in the current state.     
         *
         * @param status the returned status by disable method.
         */
        static void enableAll(bool status=true);
        
        /**
         * Enables all maskable interrupts.
         *
         * @param status the returned status by disable method.
         * @param ret    value which will be returned.     
         * @return given value.     
         */
        template<class Type>
        static inline bool enableAll(bool status, Type ret)
        {
            enableAll(status);
            return ret;   
        }    
        
        /**
         * Initializes the module.
         *
         * @param config a target processor configuration.
         * @return true if no errors have been occurred.
         */   
        static bool initialize(const ::Configuration config);
        
        /**
         * Deinitializes the module.
         */
        static void deinitialize();
      
    };
}
#endif // MODULE_INTERRUPT_HPP_