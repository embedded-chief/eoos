/**
 * Skeleton interrupt task class with default settings.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2017 Sergey Baigudin
 * @license   http://baigudin.software/license/
 * @link      http://baigudin.software
 */
#ifndef BOOS_SYSTEM_INTERRUPT_TASK_HPP_
#define BOOS_SYSTEM_INTERRUPT_TASK_HPP_

#include "boos.Object.hpp"
#include "boos.api.Task.hpp"

namespace system
{
  class InterruptTask : public ::Object<>, public ::api::Task
  {
    typedef ::Object<> Parent;  
    
  public:
  
    /** 
     * Constructor.
     */    
    InterruptTask() : Parent(){}

    /** 
     * Destructor.
     */
    virtual ~InterruptTask(){}
    
    /**
     * Tests if this object has been constructed.
     *
     * @return true if object has been constructed successfully.
     */    
    virtual bool isConstructed() const
    {
      return this->Parent::isConstructed();
    }   
    
    /**
     * Returns size of interrupt stack.
     *
     * The method returns size of interrupt stack in bytes which should be allocated for the task.
     *
     * @return stack size in bytes.
     */  
    virtual int32 stackSize() const
    {
      return 0x800;
    }
    
  private:    

    /**
     * Copy constructor.
     *
     * @param obj reference to source object.
     */
    InterruptTask(const InterruptTask& obj);

    /**
     * Assignment operator.
     *
     * @param obj reference to source object.
     * @return reference to this object.     
     */
    InterruptTask& operator =(const InterruptTask& obj);    

  };
}
#endif // BOOS_SYSTEM_INTERRUPT_TASK_HPP_