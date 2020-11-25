Queue<T>::Queue(const Queue<T> & other) :
  m_front(NULL),
  m_back(NULL)
{
  Node<T> * other = other.m_front;
  if (other)
  {
    Node<T> * curr = m_front = new Node<T>(other->m_data());
    while (other->m_front)
    {
      other = other->m_front;
      curr = curr->m_next = new Node<T>(other->m_data());
    }
    m_back = curr;
  }
}

void Queue<T>::push(const T & value)
{
  m_back = m_back->next = new Node<T>(value);
}

void Queue<T>::pop()
{
  if (m_front)
  {
    Node<T> * del = m_front;
    m_front = m_front->m_next;
    delete del;
  }
}

Queue<T> & Queue<T>::operator=(const Queue<T> & rhs)
{
  if (this != &rhs)
  {
    clear();
    Node<T> * other = rhs.m_front;
    if (other)
    {
      Node<T> * curr = m_front = new Node<T>(other->m_data);
      while (other->m_next)
      {
        other = other->m_next;
        curr = curr->m_next = new Node<T>(other->m_data);
      }
      m_back = curr;
    }
  }
}

void Queue<T>::clear()
{
  while (m_front)
  {
    Node<T> * del = m_front;
    m_front = m_front->m_next;
    delete del;
  }
  m_front = NULL;
  m_back = NULL;
}

