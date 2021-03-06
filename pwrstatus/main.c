�
a�YPc           @   s�   d  Z  d d l Z d d l Z d d l Z d d l Z d d l Z d d l Z d d l Z d d d d g Z d e	 f d �  �  YZ
 d e	 f d �  �  YZ d e	 f d	 �  �  YZ d e	 f d
 �  �  YZ d S(   s�   Base classes for progress reporting.

Custom progress classes should inherit from these classes. They can also be
used as dummy progress classes which simply do nothing.
i����Nt   AcquireProgresst   CdromProgresst   InstallProgresst
   OpProgressc           B   sz   e  Z d  Z d Z Z Z Z Z d Z Z	 Z
 d �  Z d �  Z d �  Z d �  Z d �  Z d �  Z d	 �  Z d
 �  Z RS(   s�   Monitor object for downloads controlled by the Acquire class.

    This is an mostly abstract class. You should subclass it and implement the
    methods to get something useful.
    g        i    c         C   s   d S(   s<   Invoked when an item is successfully and completely fetched.N(    (   t   selft   item(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   done0   s    c         C   s   d S(   s*   Invoked when an item could not be fetched.N(    (   R   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   fail3   s    c         C   s   d S(   s0   Invoked when some of the item's data is fetched.N(    (   R   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   fetch6   s    c         C   s   d S(   s�   Invoked when an item is confirmed to be up-to-date.

        Invoked when an item is confirmed to be up-to-date. For instance,
        when an HTTP download is informed that the file on the server was
        not modified.
        N(    (   R   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   ims_hit9   s    c         C   s   t  S(   s�  Prompt the user to change the inserted removable media.

        The parameter 'media' decribes the name of the media type that
        should be changed, whereas the parameter 'drive' should be the
        identifying name of the drive whose media should be changed.

        This method should not return until the user has confirmed to the user
        interface that the media change is complete. It must return True if
        the user confirms the media change, or False to cancel it.
        (   t   False(   R   t   mediat   drive(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   media_changeA   s    c         C   s   t  S(   s  Periodically invoked while the Acquire process is underway.

        This method gets invoked while the Acquire progress given by the
        parameter 'owner' is underway. It should display information about
        the current state.

        This function returns a boolean value indicating whether the
        acquisition should be continued (True) or cancelled (False).
        (   t   True(   R   t   owner(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   pulseN   s    
c         C   sL   d |  _  d |  _ d |  _ d |  _ d |  _ d |  _ d |  _ d |  _ d S(   s0   Invoked when the Acquire process starts running.g        i    N(   t   current_bytest   current_cpst   current_itemst   elapsed_timet   fetched_bytest
   last_bytest   total_bytest   total_items(   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   startZ   s    							c         C   s   d S(   s/   Invoked when the Acquire process stops running.N(    (   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   stopf   s    (   t   __name__t
   __module__t   __doc__R   R   R   R   R   R   R   R   R   R   R   R	   R   R   R   R   (    (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyR    %   s   							c           B   s/   e  Z d  Z d Z d �  Z d �  Z d �  Z RS(   s
  Base class for reporting the progress of adding a cdrom.

    Can be used with apt_pkg.Cdrom to produce an utility like apt-cdrom. The
    attribute 'total_steps' defines the total number of steps and can be used
    in update() to display the current progress.
    i    c         C   s   d S(   s�   Ask for the name of the cdrom.

        If a name has been provided, return it. Otherwise, return None to
        cancel the operation.
        N(    (   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   ask_cdrom_namet   s    c         C   s   d S(   s�   Ask for the CD-ROM to be changed.

        Return True once the cdrom has been changed or False to cancel the
        operation.
        N(    (   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   change_cdrom{   s    c         C   s   d S(   s�   Periodically invoked to update the interface.

        The string 'text' defines the text which should be displayed. The
        integer 'current' defines the number of completed steps.
        N(    (   R   t   textt   current(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   update�   s    (   R   R   R   t   total_stepsR   R   R"   (    (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyR   j   s
   		c           B   s�   e  Z d  Z d \ Z Z Z Z d �  Z d �  Z d �  Z	 d �  Z
 d	 �  Z d
 �  Z d �  Z d �  Z d �  Z d �  Z d �  Z d �  Z RS(   s4   Class to report the progress of installing packages.i    g        g�������?t    c         C   sh   t  j �  \ |  _ |  _ t  j |  j d � |  _ t  j |  j d � |  _ t j |  j t j t  j	 � d  S(   Nt   wt   r(
   t   ost   pipet   statusfdt   writefdt   fdopent   write_streamt   status_streamt   fcntlt   F_SETFLt
   O_NONBLOCK(   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   __init__�   s    c         C   s   d S(   s   (Abstract) Start update.N(    (   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   start_update�   s    c         C   s   d S(   s+   (Abstract) Called when update has finished.N(    (   R   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   finish_update�   s    c         C   s   d S(   s>   (Abstract) Called when a error is detected during the install.N(    (   R   t   pkgt   errormsg(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   error�   s    c         C   s   d S(   sA   (Abstract) Called when a conffile question from dpkg is detected.N(    (   R   R!   t   new(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   conffile�   s    c         C   s   d S(   s.   (Abstract) Called when the APT status changed.N(    (   R   R4   t   percentt   status(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   status_change�   s    c         C   s   d S(   s/   (Abstract) Called when the dpkg status changed.N(    (   R   R4   R:   (    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt   dpkg_status_change�   s    c         C   s   d S(   s�   (Abstract) Sent just before a processing stage starts.

        The parameter 'stage' is one of "upgrade", "install"
        (both sent before unpacking), "configure", "trigproc", "remove",
        "purge". This method is used for dpkg only.
        N(    (   R   R4   t   stage(    (    s5   /usr/lib/python2.7/dist-packages/apt/progress/base.pyt
   processing�   s    c      	   C   s�   |  j  �  } | d k r� y# t j | j |  j j �  � � Wq� t k
 r� t j t j t j d d d t	 |  j j �  � d | � � q� t
 k
 r� } t j j d | � t j t j j � q� Xn  | |  _ |  j �  } t j | � S(   s�  Install using the object 'obj'.

        This functions runs install actions. The parameter 'obj' may either
        be a PackageManager object in which case its do_install() method is
        called or the path to a deb file.

        If the object is a PackageManager, the functions returns the result
        of calling its do_install() method. Otherwise, the��  L   B��B    �  �