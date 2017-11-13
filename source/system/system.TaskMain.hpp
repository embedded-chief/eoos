/** 
 * User main task class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef SYSTEM_TASK_MAIN_HPP_
#define SYSTEM_TASK_MAIN_HPP_

#include "system.TaskBase.hpp"

namespace system
{
    /**
     * User main thread.
     */ 
    class TaskMain : public ::system::TaskBase
    {
        typedef ::system::TaskBase Parent;
      
    public:
    
        /** 
         * Constructor.
         *
         * @param stack stack size in byte.
         */
        TaskMain(int32 stack) : Parent(),
            error_ (-1),
            stack_ (stack){
        }
        
        /** 
         * Destructor.
         */
        virtual ~TaskMain()
        {
        }
        
        /**
         * The method with self context.
         */  
        virtual void main()
        {
            error_ = ::Main::main();
        }
        
        /**
         * Returns execution error.
         */  
        int32 error()
        {
            return error_;
        }
        
        /**
         * Returns size of task stack.
         *
         * @return stack size in bytes.
         */  
        virtual int32 getStackSize() const
        {
            return stack_;
        }            
      
    private:
      
        /**
         * Copy constructor.
         *
         * @param obj reference to source object.
         */
        TaskMain(const TaskMain& obj);
        
        /**
         * Assignment operator.
         *
         * @param obj reference to source object.
         * @return reference to this object.     
         */
        TaskMain& operator =(const TaskMain& obj);      
        
        /**
         * Execution error.
         */
        int32 error_;

        /**
         * Stack size in byte.
         */        
        int32 stack_;
      
    };
}
#endif // SYSTEM_TASK_MAIN_HPP_