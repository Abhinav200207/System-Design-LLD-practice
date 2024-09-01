import java.util.List;

public class MeetingManager {
    private List<Room> roomList;

    public MeetingManager(List<Room> rooms) {
        this.roomList = rooms;
    }

    public Meeting scheduleMeeting(int start, int end, List<Attendee> attendees){
        boolean canSchedule = true;
        Room roomtoSchedule = null;
        for (Room room : roomList){
            if (room.isAvailable(start,end)){
                roomtoSchedule = room;
                break;
            }
        }
        for (Attendee attendee : attendees){
            if (!attendee.isAvailable(start,end)){
                canSchedule = false;
            }
        }
        if (roomtoSchedule != null && canSchedule){
            return roomtoSchedule.scheduleMeeting(start, end, attendees);
        }
        System.out.println("tight schedule");
        return null;
    }
}
